#include <Arduino.h>
#include <PID_v1.h>

double Setpoint, Input, Output;
double Kp=2, Ki=5, Kd=1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

#define AB 6
#define AA 7
#define encX 2
#define encY 3

void setSpeedDir(uint8_t speed, uint8_t dir);
void encoder(void);

uint8_t ms = 10;
uint8_t hitrost = 255;
int32_t cnt = 0;
int32_t stari_cnt = 0;
int32_t premik = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(AB, OUTPUT);
  pinMode(AA, OUTPUT);
  pinMode(encX, INPUT);
  pinMode(encY, INPUT);
  attachInterrupt(digitalPinToInterrupt(encX), encoder, RISING);
  Setpoint = 1000;
  myPID.SetMode(AUTOMATIC);
}

void loop()
{ 
  Input = cnt;
  myPID.Compute();
  setSpeedDir(Output, 0);
  Serial.println(cnt);
}

void setSpeedDir(uint8_t speed, uint8_t dir)
{
  if (dir == 0)
  {
    digitalWrite(AA, LOW);
    analogWrite(AB, speed);
  }
  else
  {
    digitalWrite(AB, LOW);
    analogWrite(AA, speed);
  }
}

void encoder(void)
{
  if (digitalRead(encY) == 1) {
    cnt=cnt+1;
  }
  else {
    cnt=cnt-1;
  }
}