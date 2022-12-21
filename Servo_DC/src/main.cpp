#include <Arduino.h>
#define PWM 11
#define dir_clk 4
#define dir_en 7
#define dir_ser 8
#define dir_latch 12
#define encX 2
#define encY 9

void setStepCmd(uint8_t data);
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
  pinMode(PWM, OUTPUT);
  pinMode(dir_clk, OUTPUT);
  pinMode(dir_en, OUTPUT);
  pinMode(dir_ser, OUTPUT);
  pinMode(dir_latch, OUTPUT);
  pinMode(encX, INPUT);
  pinMode(encY, INPUT);
  digitalWrite(PWM, HIGH);
  digitalWrite(dir_en, HIGH);

  attachInterrupt(digitalPinToInterrupt(encX), encoder, RISING);
  setSpeedDir(hitrost, 0);
}

void loop()
{ 
  premik = cnt - stari_cnt;
  stari_cnt = cnt;
  delay(1000);
  Serial.println(premik/32.0*60.0);
}

void setStepCmd(uint8_t data)
{
  digitalWrite(dir_en, HIGH);
  digitalWrite(dir_latch, LOW);
  shiftOut(dir_ser, dir_clk, MSBFIRST, data);
  digitalWrite(dir_latch, HIGH);
  digitalWrite(dir_en, LOW);
}

void setSpeedDir(uint8_t speed, uint8_t dir)
{
  if (dir == 0)
  {
    setStepCmd(0x04);
  }
  else
  {
    setStepCmd(0x08);
  }
  analogWrite(PWM, speed);
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