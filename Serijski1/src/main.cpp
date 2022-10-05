#include <Arduino.h>
uint8_t pepi = 100;
char crka = 'a';

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(pepi);
  Serial.println(pepi, HEX);
  Serial.println(pepi, BIN);
  Serial.println(crka);
  delay(100);
}