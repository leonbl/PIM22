#include <Arduino.h>
#include "STM32FreeRTOS.h"
#define l1 10
#define l2 9
SemaphoreHandle_t serSem;
void led1(void* arg){
  UNUSED(arg);
  while(1){
    digitalWrite(l1, HIGH);
    delay(100);
    digitalWrite(l1, LOW);
    delay(100);
  }
}

void led2(void* arg){
  UNUSED(arg);
  while(1){
    digitalWrite(l2, HIGH);
    delay(77);
    digitalWrite(l2, LOW);
    delay(77);
  }
}
void izpis1(void* arg){
  UNUSED(arg);
  while(1)
  {
    if(xSemaphoreTake(serSem, (TickType_t)5) == 1){
     Serial.println("En dokaj dolg niz za izpis po serijski povezavi!\n\r");
     xSemaphoreGive(serSem);
    }
    vTaskDelay(1);
  }
}
void izpis2(void* arg){
  UNUSED(arg);
  while(1)
  {
    if(xSemaphoreTake(serSem, (TickType_t)5) == 1){
      Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\r");
      xSemaphoreGive(serSem);
    }
    vTaskDelay(1);
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  serSem = xSemaphoreCreateMutex();
  xSemaphoreGive(serSem);
  xTaskCreate(led1, NULL, 256, NULL, 1, NULL);
  xTaskCreate(led2, NULL, 256, NULL, 1, NULL);
  xTaskCreate(izpis1, NULL, 256, NULL, 1, NULL);
  xTaskCreate(izpis2, NULL, 256, NULL, 1, NULL);
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}