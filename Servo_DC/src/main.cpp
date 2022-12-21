#include <Arduino.h>
#include <PID_v1.h>

double Setpoint, Input, Output;
double Kp=0.02, Ki=0.01, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

#define AB 6
#define AA 7
#define encX 2
#define encY 3

void setSpeedDir(int32_t speed);
void encoder(void);

uint8_t ms = 10;
uint8_t hitrost = 255;
int32_t cnt = 0;
int32_t stari_cnt = 0;
int32_t premik = 0;
int32_t ser = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(AB, OUTPUT);
  pinMode(AA, OUTPUT);
  pinMode(encX, INPUT);
  pinMode(encY, INPUT);
  attachInterrupt(digitalPinToInterrupt(encX), encoder, RISING);
  Setpoint = 1000;
  myPID.SetOutputLimits(-255, 255);
  myPID.SetMode(AUTOMATIC);
}

void loop()
{ 
/*
  Input = cnt;
  myPID.Compute();
  if(Output > 0){
    setSpeedDir(Output, 0);
  }
  else {
    setSpeedDir(abs(Output), 1);
  }
  ser++;
  if((ser % 1000) == 0){
    Serial.print(cnt);
    Serial.print(" ");
    Serial.println(Output);
  }
  */
 for(int n = 0; n>-255; n--){
    setSpeedDir(n);
    delay(200);
 }
}

void setSpeedDir(int32_t speed)
{
  if (speed > 0)
  {
    digitalWrite(AA, LOW);
    analogWrite(AB, speed);
    Serial.print(cnt);
    Serial.print(" levo ");
    Serial.println(speed);
  }
  else
  {
    digitalWrite(AB, LOW);
    speed = -speed;
    analogWrite(AA, speed);
    Serial.print(cnt);
    Serial.print(" desno ");
    Serial.println(speed);
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