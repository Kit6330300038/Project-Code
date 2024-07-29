#define LDR 39
#define POT 34
#define D17 26
#define D18 27
#define LED 2
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 32, &Wire);

bool sToggle = true;
bool tS = false;
long lasttime10 = 0, lasttime500 = 0, lasttime1000 = 0;
int mintime = 0, sectime = 0;
int ldr_value;
int pot_value;
float ldr_volt;
float pot_volt;

void IRAM_ATTR isrSW1() {
  tS = false;
}
void IRAM_ATTR isrSW2() {
  tS = true;
}


void setup()
{
  Serial.begin(112500);
  pinMode(D17, INPUT_PULLUP);
  pinMode(D18, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  attachInterrupt(digitalPinToInterrupt(D18), isrSW2,CHANGE);
  attachInterrupt(digitalPinToInterrupt(D17), isrSW1,CHANGE);
}

void loop()
{ //10
  if (millis() - lasttime10 >= 10)
  { lasttime10 = millis();
    ldr_value = analogRead(LDR);
    pot_value = analogRead(POT);
    ldr_volt = ldr_value * 3.3 / 4095;
    pot_volt = pot_value * 3.3 / 4095;
    Serial.printf("0.00,3.30,%.2f,%.2f\n", ldr_volt, pot_volt);
  }
  //500
  if (millis() - lasttime500 >= 500)
  { lasttime500 = millis();
    sToggle = !sToggle;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    digitalWrite(LED, sToggle);
    if (sToggle || tS)
    {
      display.printf("Time: %02d:%02d", mintime, sectime);
    } else
    {
      display.printf("Time: %02d %02d", mintime, sectime);
    }
    display.setCursor(0, 12);
    display.printf("LDRDEC:%04d VOLT:%.1fV", ldr_value, ldr_volt);
    display.setCursor(0, 24);
    display.printf("POTDEC:%04d VOLT:%.1fV", pot_value, pot_volt);
    display.display();
  }
  //1000
  if (millis() - lasttime1000 >= 1000 && tS == false)
  { lasttime1000 = millis();
    sectime++;
    if (sectime >= 60)
    { sectime = 0;
      mintime++;
    } if (mintime >= 60)
    { mintime = 0;
    }
  }
}
