#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  uint8_t tipka; 
  tipka = digitalRead(A1);
  Serial.println(tipka);
  digitalWrite(13, tipka);
  delay(500);
}