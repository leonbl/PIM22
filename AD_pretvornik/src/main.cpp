#include <Arduino.h>

int vklop=1;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int napetost_d = analogRead(A0);
  int osvet = analogRead(A1);
  float napetost_f = 5.0 / 1023.0 * napetost_d;
  Serial.println(osvet);
  if(napetost_f > 2.5){
    digitalWrite(12, LOW);
  }
  else {
    if(osvet > 300){
      digitalWrite(12, HIGH);
    }
    else {
      digitalWrite(12, LOW);
    }

  }
  delay(500);
}