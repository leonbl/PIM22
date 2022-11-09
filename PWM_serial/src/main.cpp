#include <Arduino.h>
char znak;
char prejeto[100];
char pwm1[4];
char pwm2[4];
int index=0;

void preberi_podatke(void);

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int stevilo_znakov = Serial.available();
  if(stevilo_znakov > 0){
    znak = Serial.read();
    if(znak==';'){
      preberi_podatke();
      index = 0;
    }
    else {
      prejeto[index] = znak;
      index++;
    }
  }

}

void preberi_podatke(void){
  for(int n=0;n<3;n++){
    pwm1[n]=prejeto[n];
  }
  for(int n=3;n<6;n++){
    pwm2[n-3]=prejeto[n];
  }
  Serial.println(pwm1);
  Serial.println(pwm2);
     
  int p1 = atoi(pwm1[0])*100+atoi(pwm1[1])*10+atoi(pwm1[2]);
  analogWrite(10, p1);
  int p2 = atoi(pwm2[0])*100+atoi(pwm2[1])*10+atoi(pwm2[2]);
  analogWrite(11, p2);
}