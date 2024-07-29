#include "EEPROM.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 32, &Wire);
#define eeprom1 0
#define eeprom2 38
#define pot 34
#define SW14 16   // Addr Nisit3X (139)
#define SW15 17   // Addr 0
#define SW10 5    // Write EEPROM
#define LED 25
char charBuffer[100];
int var0, var1, var2, var3;
int pot_value = 0;
long lasttime10ms = 0;
long lasttime1000ms = 0;
bool stateToogle = true;
int stateMode = 0;  // 0 = addr0, 1 = addrNisit


void setup() {
  Serial.begin(115200);
  Serial.printf("Start Firmware\n");

  delay(1000);

  if (!EEPROM.begin(140)) {
    Serial.println("Failed init EEPROM");
    delay(1000);
    ESP.restart();
  }
  Serial.println("Success init EEPROM\n");
  var0 = EEPROM.readUChar(eeprom1);   // Addr0
  var0 = EEPROM.readUChar(eeprom2);   // Addr Nisit3X
  Serial.printf("Read EEPROM Addr0 = %d\n", var0);

  //Setting PWM
  ledcSetup(0, 1000, 8);  // channel0, freq1khz, bitres 8bit (0-255)
  ledcAttachPin(LED, 0); // led gpio21(25), map pwm channel0
  ledcWrite(0, var0);   //   pwm channel0 (gpio21) output pwm = var0
  Serial.printf("Send PWM %d to GPIO21\n", var0);

  //Read Analog GPIO34
  pot_value = analogRead(pot);

  //Drive OLED LCD
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // Clear, Color, Size, Cursor, Print, Display
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.printf("EEPROM   ADC:%04d", pot_value);
  display.setCursor(0, 10);
  display.printf("Address: %04d (0x%03x)", 0, 0);
  display.setCursor(0, 20);
  display.printf("Data: %03d", var0);
  display.display();
  Serial.println("Display OLED LCD");

  pinMode(SW10, INPUT_PULLUP);
  pinMode(SW14, INPUT_PULLUP);
  pinMode(SW15, INPUT_PULLUP);
  pinMode(2, OUTPUT);
}

void loop() {
  // 10ms
  if (millis() - lasttime10ms >= 10) {
    lasttime10ms = millis();
    // Mode Addr 0
    if (digitalRead(SW15) == LOW) {
      stateMode = 0;
    }
    // Mode Addr Nisit3X
    if (digitalRead(SW14) == LOW) {
      stateMode = 1;
    }

    if (stateMode == 0) {
      var0 = EEPROM.readUChar(eeprom1);   // var0 = 0 - 255

      //Setting PWM
      ledcWrite(0, var0);   //   pwm channel0 (gpio21) output pwm = var0

      //Read Analog GPIO34
      pot_value = analogRead(pot);

      // Clear, Color, Size, Cursor, Print, Display
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.printf("EEPROM   ADC:%04d", pot_value);
      display.setCursor(0, 10);
      display.printf("Address: %04d (0x%03x)", 0, 0);
      display.setCursor(0, 20);
      display.printf("Data: %03d", var0);
      display.display();
      
    } else {
      var1 = EEPROM.readUChar(eeprom2);   // var0 = 0 - 255

      //Setting PWM
      ledcWrite(0, var1);   //   pwm channel0 (gpio21) output pwm = var0

      //Read Analog GPIO34
      pot_value = analogRead(pot);

      // Clear, Color, Size, Cursor, Print, Display
      display.clearDisplay();
      display.setTextColor(SSD1306_WHITE);
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.printf("EEPROM   ADC:%04d", pot_value);
      display.setCursor(0, 10);
      display.printf("Address: %04d (0x%03x)", eeprom2, eeprom2);
      display.setCursor(0, 20);
      display.printf("Data: %03d", var1);
      display.display();
    }

    if (digitalRead(SW10) == LOW) {
      if (stateMode == 0) {
        // Addr0
        pot_value = analogRead(pot);  // 12bit
        int covn8bit = pot_value * 255 / 4095; // convert 12bit to 8bit
        EEPROM.writeUChar(eeprom1, covn8bit);    // 8bit
        EEPROM.commit();

        Serial.printf("Write EEPROM Addr %d = %d\n", 0, covn8bit);
      } else {
        pot_value = analogRead(pot);  // 12bit
        int covn8bit = pot_value * 255 / 4095; // convert 12bit to 8bit
        EEPROM.writeUChar(eeprom2, covn8bit);    // 8bit
        EEPROM.commit();

        Serial.printf("Write EEPROM Addr %d = %d\n", 0, covn8bit);
      }
    }
  }

  if (millis() - lasttime1000ms >= 1000) {
    lasttime1000ms = millis();
    stateToogle = !stateToogle;
    digitalWrite(2, stateToogle);

    if (stateMode == 0) {
      Serial.printf("EEPROM ADC %04d Addr %d = %d\n", pot_value, eeprom1, var0);

    } else {
      Serial.printf("EEPROM ADC %04d Addr %d = %d\n", pot_value, eeprom2, var1);
    }
  }
}
