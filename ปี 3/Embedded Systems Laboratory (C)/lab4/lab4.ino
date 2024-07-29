#define LED_ON LOW
#define LED_OFF HIGH
#define DG1 23
#define DG2 25
#define DG3 18
#define DG4 14
#define A 32
#define B 13
#define C 5
#define D 22
#define E 19
#define F 33
#define G 27
#define DP 21
#define DPColon 26
hw_timer_t *timer1 = NULL , *timer0 = NULL;
unsigned int number = 0;
unsigned int tmpnumber1, tmpnumber2, tmpnumber3, tmpnumber4;
int status7Seg = 1, time1 = 0, time2 = 0;
bool stateToggle = true, addtime = true;
void IRAM_ATTR timer1_callback( void );
void IRAM_ATTR showNumber(int num);
void IRAM_ATTR timer0_callback( void );

void setup() {
  number = 0;
  tmpnumber1 = number / 1000;
  tmpnumber2 = (number - ((tmpnumber1) * 1000)) / 100;
  tmpnumber3 = (number - (tmpnumber1 * 1000) - (tmpnumber2 * 100)) / 10;
  tmpnumber4 = (number - (tmpnumber1 * 1000) - (tmpnumber2 * 100) - (tmpnumber3 * 10));
  Serial.begin( 115200 );
  Serial.printf( "\nShow Number : %d\n", number);
  Serial.printf( "\nDG1:%d DG2:%d DG3:%d DG4:%d\n", tmpnumber1, tmpnumber2, tmpnumber3,
                 tmpnumber4);
  pinMode(DG1, OUTPUT); pinMode(DG2, OUTPUT); pinMode(DG3, OUTPUT); pinMode(DG4, OUTPUT);
  pinMode(DPColon, OUTPUT);
  pinMode(A, OUTPUT); pinMode(B, OUTPUT); pinMode(C, OUTPUT); pinMode(D, OUTPUT);
  pinMode(E, OUTPUT); pinMode(F, OUTPUT); pinMode(G, OUTPUT); pinMode(DP, OUTPUT);
  // SLOW 1M  MED 20K  FAST 4K timer1
  timer1 = timerBegin( 1, 80, true );
  timerAlarmWrite( timer1, 4000, true );
  timerAttachInterrupt( timer1, &timer1_callback, true );
  timerAlarmEnable( timer1 );
  // timer0
  timer0 = timerBegin( 0, 8000, true );
  timerAlarmWrite( timer0, 10000, true );
  timerAttachInterrupt( timer0, &timer0_callback, true );
  timerAlarmEnable( timer0 );
}

void loop()
{ if (Serial.available() > 0)
  { String w = Serial.readString();
    int num = w.toInt();
    if (num == 2) {
      Serial.printf("Rx interrupt 2 : Clock stop\n");
      addtime = false;
    }
    else if (num == 1)
    { Serial.printf("Rx interrupt 1 : Clock continue\n");
      addtime = true;
    }
  }
}

void settime(void)
{ if (addtime == true)
  {
    time2++;
  }
  if (time2 >= 60)
  { time1++;
    time2 = 0;
    if (time1 >= 60)
    { time1 = 0;
    }
  }  
  tmpnumber1 = time1 / 10;
  tmpnumber2 = (time1 - ((tmpnumber1) * 10));
  tmpnumber3 = time2 / 10;
  tmpnumber4 = (time2 - (tmpnumber3 * 10));
  Serial.printf("Clock -> %02d:%02d\n\r", time1, time2);
}

void IRAM_ATTR timer0_callback( void )
{ digitalWrite(DPColon, stateToggle);
  stateToggle = !stateToggle;

  settime();
}
void IRAM_ATTR timer1_callback( void )
{
  if (status7Seg == 1)
  {
    showNumber(tmpnumber1);
    digitalWrite( DG1, LOW );
    digitalWrite( DG2, HIGH );
    digitalWrite( DG3, HIGH );
    digitalWrite( DG4, HIGH );
    status7Seg = 2;
  }
  else if (status7Seg == 2)
  {
    showNumber(tmpnumber2);
    digitalWrite( DG1, HIGH );
    digitalWrite( DG2, LOW);
    digitalWrite( DG3, HIGH);
    digitalWrite( DG4, HIGH);
    status7Seg = 3;
  }
  else if (status7Seg == 3)
  {
    showNumber(tmpnumber3);
    digitalWrite( DG1, HIGH );
    digitalWrite( DG2, HIGH );
    digitalWrite( DG3, LOW );
    digitalWrite( DG4, HIGH );
    status7Seg = 4;
  }
  else if (status7Seg == 4)
  {
    showNumber(tmpnumber4);
    digitalWrite( DG1, HIGH );
    digitalWrite( DG2, HIGH );
    digitalWrite( DG3, HIGH );
    digitalWrite( DG4, LOW );
    status7Seg = 1;
  }
  else
  {
    status7Seg = 1;
  }
}
void IRAM_ATTR showNumber(int num)
{
  if (num == 0)
  {
    digitalWrite( A, HIGH ); digitalWrite( B, HIGH ); digitalWrite( C, HIGH );
    digitalWrite( D, HIGH ); digitalWrite( E, HIGH ); digitalWrite( F, HIGH ); digitalWrite( G, LOW );
  }
  else if (num == 1) {
    digitalWrite( A, LOW ); digitalWrite( B, HIGH ); digitalWrite( C, HIGH );
    digitalWrite( D, LOW ); digitalWrite( E, LOW ); digitalWrite( F, LOW ); digitalWrite( G, LOW );
  }
  else if (num == 2) {
    digitalWrite( A, HIGH ); digitalWrite( B, HIGH ); digitalWrite( C, LOW );
    digitalWrite( D, HIGH ); digitalWrite( E, HIGH ); digitalWrite( F, LOW ); digitalWrite( G, HIGH );
  }
  else if (num == 3) {
    digitalWrite( A, HIGH ); digitalWrite( B, HIGH ); digitalWrite( C, HIGH );
    digitalWrite( D, HIGH ); digitalWrite( E, LOW ); digitalWrite( F, LOW ); digitalWrite( G, HIGH );
  }
  else if (num == 4) {
    digitalWrite( A, LOW ); digitalWrite( B, HIGH ); digitalWrite( C, HIGH );
    digitalWrite( D, LOW ); digitalWrite( E, LOW ); digitalWrite( F, HIGH ); digitalWrite( G, HIGH );
  }
  else if (num == 5) {
    digitalWrite( A, HIGH ); digitalWrite( B, LOW ); digitalWrite( C, HIGH );
    digitalWrite( D, HIGH ); digitalWrite( E, LOW ); digitalWrite( F, HIGH ); digitalWrite( G, HIGH );
  }
  else if (num == 6) {
    digitalWrite( A, HIGH ); digitalWrite( B, LOW ); digitalWrite( C, HIGH );
    digitalWrite( D, HIGH ); digitalWrite( E, HIGH ); digitalWrite( F, HIGH ); digitalWrite( G, HIGH );
  }
  else if (num == 7) {
    digitalWrite( A, HIGH ); digitalWrite( B, HIGH ); digitalWrite( C, HIGH );
    digitalWrite( D, LOW ); digitalWrite( E, LOW ); digitalWrite( F, LOW ); digitalWrite( G, LOW );
  }
  else if (num == 8) {
    digitalWrite( A, HIGH ); digitalWrite( B, HIGH ); digitalWrite( C, HIGH );
    digitalWrite( D, HIGH ); digitalWrite( E, HIGH ); digitalWrite( F, HIGH ); digitalWrite( G, HIGH );
  }
  else if (num == 9) {
    digitalWrite( A, HIGH ); digitalWrite( B, HIGH ); digitalWrite( C, HIGH );
    digitalWrite( D, HIGH ); digitalWrite( E, LOW ); digitalWrite( F, HIGH ); digitalWrite( G, HIGH );
  }
  else {
    digitalWrite( A, LOW ); digitalWrite( B, LOW ); digitalWrite( C, LOW );
    digitalWrite( D, LOW ); digitalWrite( E, LOW ); digitalWrite( F, LOW ); digitalWrite( G, LOW );
  }
}
