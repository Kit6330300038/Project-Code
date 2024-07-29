#include <SPI.h>
SPISettings MCP4922(20000000,MSBFIRST,SPI_MODE0);
#define SS 22
#define LDAC 21
#define LED 2
bool stateToggle = true;
hw_timer_t *timer0 = NULL;

void outA2V2()
{ SPI.beginTransaction(MCP4922);
  digitalWrite(SS,LOW);
  SPI.transfer16(0x3AAA);
  digitalWrite(SS,HIGH);
  delay(1);
  digitalWrite(LDAC,LOW);
  delay(1);
  digitalWrite(LDAC,HIGH);
  SPI.endTransaction();
}

void outA0V0()
{ SPI.beginTransaction(MCP4922);
  digitalWrite(SS,LOW);
  SPI.transfer16(0x3000);
  digitalWrite(SS,HIGH);
  delay(1);
  digitalWrite(LDAC,LOW);
  delay(1);
  digitalWrite(LDAC,HIGH);
  SPI.endTransaction();
}

void outB3V3()
{ SPI.beginTransaction(MCP4922);
  digitalWrite(SS,LOW);
  SPI.transfer16(0xBFFF);
  digitalWrite(SS,HIGH);
  delay(1);
  digitalWrite(LDAC,LOW);
  delay(1);
  digitalWrite(LDAC,HIGH);
  SPI.endTransaction();
}

void outB0V0()
{ SPI.beginTransaction(MCP4922);
  digitalWrite(SS,LOW);
  SPI.transfer16(0xB000);
  digitalWrite(SS,HIGH);
  delay(1);
  digitalWrite(LDAC,LOW);
  delay(1);
  digitalWrite(LDAC,HIGH);
  SPI.endTransaction();
}

void IRAM_ATTR timer_isr()
{ stateToggle=!stateToggle;
  digitalWrite(LED,stateToggle);
  if(stateToggle==true)
  { outB3V3();
    20outA0V0();
  }else
  { outB0V0();
    outA2V2();
  }
  
}

void setup() {
  pinMode(SS,OUTPUT);
  pinMode(LDAC,OUTPUT);
  pinMode(LED,OUTPUT);
  SPI.begin();
  digitalWrite(LDAC,HIGH);

  timer0 = timerBegin(0,80,true);
  timerAlarmWrite(timer0,1000000,true);
  timerAttachInterrupt(timer0,&timer_isr,true);
  timerAlarmEnable(timer0);
}

void loop() {
  // put your main code here, to run repeatedly:
}
