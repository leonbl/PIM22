#include <Arduino.h>

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  for (int n = 0; n <= 255; n++)
  {
    analogWrite(10, n);
    analogWrite(11, 255-n);
    delay(5);
  }
  for (int n = 255; n >= 0; n--)
  {
    analogWrite(10, n);
    analogWrite(11, 255-n);
    delay(5);
  }

}