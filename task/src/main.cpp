#include <Arduino.h>
#include <TimerEvent.h>

const unsigned int led1Period = 250;
const unsigned int led2Period = 125;
const unsigned int led3Period = 45;

#define led1 10 // 2Hz
#define led2 11 // 4Hz
#define led3 12 // 11Hz

TimerEvent tim1;
TimerEvent tim2;
TimerEvent tim3;

void loop1();
void loop2();
void loop3();

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  tim1.set(led1Period, loop1);
  tim2.set(led2Period, loop2);
  tim3.set(led3Period, loop3);
}

void loop()
{
  tim1.update();
  tim2.update();
  tim3.update();
}

void loop1()
{
    digitalWrite(led1, !digitalRead(led1));
}

void loop2()
{
  digitalWrite(led2, !digitalRead(led2));
}
void loop3()
{
  digitalWrite(led3, !digitalRead(led3));
}