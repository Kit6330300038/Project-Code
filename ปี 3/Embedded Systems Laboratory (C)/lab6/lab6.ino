#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define MCP23017 0x20
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
unsigned int timePeriod = 1000;
unsigned long last_time = 0;
bool stateToogle = true;

void setDirectionOutputPortA() {
  Wire.beginTransmission(0x20);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.endTransmission();
}
void onPortA() {
  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  Wire.write(0xFF);
  Wire.endTransmission();
}
void offPortA() {
  Wire.beginTransmission(0x20);
  Wire.write(0x14);
  Wire.write(0x00);
  Wire.endTransmission();
}
void setDirectionOutputPortB() {
  Wire.beginTransmission(0x20);
  Wire.write(0x01);
  Wire.write(0x00);
  Wire.endTransmission();
}
void onPortB() {
  Wire.beginTransmission(0x20);
  Wire.write(0x13);
  Wire.write(0xFF);
  Wire.endTransmission();
}
void offPortB() {
  Wire.beginTransmission(0x20);
  Wire.write(0x15);
  Wire.write(0x00);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
    Serial.println(F("SSD1306 allocation failed"));
  }
  display.display();
  display.clearDisplay();
  // Test Draw Char
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor( 0 , 0);
  display.println(F("ESP32 I2C MCP23017"));
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("ESP32 I2C MCP23017"));
  display.setCursor(0, 8);
  display.println(F("LED 1 : ON"));
  display.setCursor(0, 16);
  display.println(F("LED 2 : OFF"));
  display.display();
  setDirectionOutputPortA();
  onPortA();
  setDirectionOutputPortB();
  offPortB();
}
void loop() {
  if ( millis() - last_time > timePeriod) {
    last_time = millis();
    stateToogle = !stateToogle;
    if (stateToogle == true) {
      onPortA();
      offPortB();
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("ESP32 I2C MCP23017"));
      display.setCursor(0, 8);
      display.println(F("LED 1 : ON"));
      display.setCursor(0, 16);
      display.println(F("LED 2 : OFF"));
      display.display();
    } else {
      offPortA();
      onPortB();
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("ESP32 I2C MCP23017"));
      display.setCursor(0, 8);
      display.println(F("LED 1 : OFF"));
      display.setCursor(0, 16);
      display.println(F("LED 2 : ON"));
      display.display();
    }
  }

}
