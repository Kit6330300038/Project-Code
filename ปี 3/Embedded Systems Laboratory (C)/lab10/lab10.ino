#include <WiFi.h>
#include <WebServer.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "EEPROM.h"
#define EEPROM_SIZE 1000
Adafruit_SSD1306 display(128, 32, &Wire);
#define NISIT 38
#define SW 5
#define LED 25
const char* ssid = "ESP32_kit S U S";
const char* password = "12345678";
int bufeeprom;

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

uint8_t LED1pin = 2;
bool LED1status = LOW;

uint8_t LED2pin = 4;
bool LED2status = LOW;

long lasttime10ms = 0;
bool stateONOFF = true;
int adcvalue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  delay(100);

  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  //Test LCD, Clear, Setfontsize, Color, Cursor, print, display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.printf("Lab10.6 WIFI");
  display.display();

  if (!EEPROM.begin(EEPROM_SIZE)) {
    Serial.println("Failed init EEPROM");
    delay(1000);
    ESP.restart();
  }
  bufeeprom = EEPROM.readUChar(NISIT);
  Serial.println("Success init EEPROM");

  ledcSetup(0, 1000, 8);
  ledcAttachPin(LED, 0);

  int buffStar = EEPROM.readUChar(0);
  if(buffStar == 1){
    LED2status = HIGH;
  }else{
    LED2status = LOW;
  }
}
void loop() {
  server.handleClient();
  if (LED1status)
  {
    digitalWrite(LED1pin, HIGH);
  }
  else
  {
    digitalWrite(LED1pin, LOW);
  }

  if (LED2status)
  {
    //digitalWrite(LED2pin, HIGH);
    ledcWrite(0, bufeeprom);
  }
  else
  {
    //digitalWrite(LED2pin, LOW);
    ledcWrite(0, 0);
  }

  if (millis() - lasttime10ms >= 10) {
    lasttime10ms = millis();
    adcvalue = analogRead(34);

    if (LED2status == HIGH) {
      ledcWrite(0,bufeeprom);
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.printf("ON   ADC:%04d", adcvalue);
      display.setCursor(0, 8);
      display.printf("Address: %d(0x%x)", NISIT, NISIT);
      display.setCursor(0, 16);
      display.printf("Data: %d(0x%x)", bufeeprom, bufeeprom);
      display.display();
    } else {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.printf("OFF  ADC:%04d", adcvalue);
      display.setCursor(0, 8);
      display.printf("Address: %d(0x%x)", NISIT, NISIT);
      display.setCursor(0, 16);
      display.printf("Data: %d(0x%x)", bufeeprom, bufeeprom);
      display.display();
    }

    if (digitalRead(SW) == LOW) {
      delay(100);
      int adcconv = (int)(adcvalue * 255 / 4095);
      EEPROM.writeUChar(NISIT, adcconv);
      EEPROM.commit();
      delay(200);
      bufeeprom = EEPROM.readUChar(NISIT);

    }

  }
}
void handle_OnConnect() {
  LED1status = LOW;
  LED2status = LOW;
  Serial.println("GPIO2 Status: OFF | GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status, LED2status));
}
void handle_led1on() {
  LED1status = HIGH;
  Serial.println("GPIO2 Status: ON");
  server.send(200, "text/html", SendHTML(true, LED2status));
}
void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO2 Status: OFF");
  server.send(200, "text/html", SendHTML(false, LED2status));
}

void handle_led2on() {
  LED2status = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status, true));

  EEPROM.writeUChar(0, 1);
  EEPROM.commit();
}

void handle_led2off() {
  LED2status = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status, false));

  EEPROM.writeUChar(0, 0);
  EEPROM.commit();
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat, uint8_t led2stat) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #3498db;}\n";
  ptr += ".button-on:active {background-color: #2980b9;}\n";
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ESP32 Web Server</h1>\n";
  ptr += "<h3>AP Mode</h3>\n";
  ptr += "<h3>IP:192.168.1.1</h3>\n";
  ptr += "<h3>PWM data:" + (String)bufeeprom +"</h3>\n";
  ptr += "<h3>LED CONTROL</h3>\n";
  if (led2stat)
  {
    ptr += "<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";
  }
  else
  {
    ptr += "<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";
  }

  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
