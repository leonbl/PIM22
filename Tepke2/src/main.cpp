#include <Arduino.h>
int staro_stanje = 0;
int vklop = 0;
void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int stanje;
  stanje = digitalRead(A2);
  delay(50);
  if((staro_stanje == 1) && (stanje == 0)){ //  je vrednost sprmenljivke staro_stanje enaka 1
                                            // in hkrati vrednost spremenljivke stanje enaka 0?
    digitalWrite(13, vklop);  // v tem primeru postavi led v stanje vklop
    vklop = ! vklop;          // negiraj vrednost v spremenljivki vklop
  }
  staro_stanje = stanje;
}