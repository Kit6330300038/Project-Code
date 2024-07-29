#include <WebServer.h>
#include <Wire.h>  // I2C library
#include "esp_system.h"
float val1, val2;
const char* ssid = "AndroidAP kit";   // Enter SSID here
const char* password = "Kitty01363";  //Enter Password here
// Set your Static IP address
IPAddress local_IP(192, 168, 43, 184);
// Set your Gateway IP address
IPAddress gateway(192, 168, 43, 1);
IPAddress subnet(255, 255, 255, 0);
WebServer server(80);
int data[2];


byte f, l;
int co2 = 0, tvoc = 0;
const char* host = "192.168.43.54";
unsigned long ltime = 0;
hw_timer_t* timer = NULL;
const int wdtTimeout = 60000;

void bootsensor() {
  Wire.beginTransmission(0x5A);  // address of sensor
  Wire.write(0xF4);              // register number
  Wire.endTransmission(true);   
  Wire.beginTransmission(0x5A);  // address of sensor
  Wire.write(0x01);              // register number
  Wire.write(0x10);              // write data to register 0x01 
  Wire.endTransmission(true);
  return;
}


void getdata() {
  Wire.beginTransmission(0x5A);
  Wire.write(0x02);
  Wire.endTransmission(true);
  Wire.requestFrom(0x5A, 4);
  f = Wire.read();
  l = Wire.read();
  data[0] = (int(f) * 256) + int(l);
  if (data[0] == 65021) {
    bootsensor();
  } else if (data[0] < 400) {
    data[0] = 400;
  } else if (data[0] > 8192) {
    data[0] = 8192;
  }
  f = Wire.read();
  l = Wire.read();
  data[1] = (int(f) * 256) + int(l);
  if (data[1] == 65021) {
    bootsensor();
  } else if (data[1] > 1187) {
    data[1] = 1187;
  }
  return;
}


void IRAM_ATTR resetModule() {
  ets_printf("reboot\n");
  esp_restart();
}


void setup() {
  // Enable serial
  Serial.begin(115200);
  Serial.println("");
  // Enable I2C
  Wire.begin();
  delay(5000);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &resetModule, true);
  timerAlarmWrite(timer, wdtTimeout * 1000, false);
  timerAlarmEnable(timer);
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());
  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP server started");
  bootsensor();
}
WiFiClient client;

void loop() {
  getdata();
  val1 = data[0];
  val2 = data[1];
  Serial.print("CCS811: ");
  Serial.print("eco2=");
  Serial.print(val1);
  Serial.print(" ppm  ");
  Serial.print("etvoc=");
  Serial.print(val2);
  Serial.print(" ppb  ");
  Serial.println();
  timerWrite(timer, 0);
  if (millis() - ltime >= 60000) {
    ltime = millis();
    client.connect(host, 80);
    client.print(String("GET http://localhost/demo/connect.php?co2=" + String(val1) + "&tvoc=" + String(val2)) + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  }
  delay(1000);
  server.handleClient();
}

void handle_OnConnect() {

  server.send(200, "text/html", SendHTML(val1, val2));
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

String SendHTML(float val1, float val2) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>Measured Air Quality</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr += "p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "<script>\n";
  ptr += "setInterval(loadDoc,1000);\n";
  ptr += "function loadDoc() {\n";
  ptr += "var xhttp = new XMLHttpRequest();\n";
  ptr += "xhttp.onreadystatechange = function() {\n";
  ptr += "if (this.readyState == 4 && this.status == 200) {\n";
  ptr += "document.body.innerHTML =this.responseText}\n";
  ptr += "};\n";
  ptr += "xhttp.open(\"GET\", \"/\", true);\n";
  ptr += "xhttp.send();\n";
  ptr += "}\n";
  ptr += "</script>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";

  ptr += "<h1>Measured Air Quality</h1>\n";

  ptr += "<p>CO2: ";
  ptr += val1;
  ptr += " ppm</p>";

  ptr += "<p>TVOC: ";
  ptr += val2;
  ptr += " ppb</p>";


  if (val2 <= 65) {
    ptr += "<h1>Air Quality : Excellent</h1>\n";
  } else if (val2 > 65 && val2 <= 220) {
    ptr += "<h1>Air Quality : Good</h1>\n";
  } else if (val2 > 220 && val2 <= 660) {
    ptr += "<h1>Air Quality : Moderate</h1>\n";
  } else if (val2 > 660 && val2 <= 1188) {
    ptr += "<h1>Air Quality : Poor</h1>\n";
  }

  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}