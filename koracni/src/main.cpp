#include <Arduino.h>
#define en1 11
#define en2 3
#define dir_clk 4
#define dir_en 7
#define dir_ser 8
#define dir_latch 12

void setStepCmd(uint8_t data);
uint8_t ms=10;

void setup()
{
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(dir_clk, OUTPUT);
  pinMode(dir_en, OUTPUT);
  pinMode(dir_ser, OUTPUT);
  pinMode(dir_latch, OUTPUT);
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  digitalWrite(dir_en, HIGH);
}

void loop()
{
  setStepCmd(0x04);
  delay(ms);
  setStepCmd(0x08);
  delay(ms);
  setStepCmd(0x02);
  delay(ms);
  setStepCmd(0x10);
  delay(ms);
}

void setStepCmd(uint8_t data)
{
  digitalWrite(dir_en, HIGH);
  digitalWrite(dir_latch, LOW);
  shiftOut(dir_ser, dir_clk, MSBFIRST, data);
  digitalWrite(dir_latch, HIGH);
  digitalWrite(dir_en, LOW);
}