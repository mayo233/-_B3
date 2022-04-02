//sample program :Blink LED0,LED2
#include "enpitshield.h"

void setup() {
  //ピンモードの初期設定
  pinMode(LED0,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop() {
  //LED0を点滅
  digitalWrite(LED0,LED_ON);
  delay(500);
  digitalWrite(LED0,LED_OFF);
  delay(500);

  //LED1を点滅
  digitalWrite(LED1,LED_ON);
  delay(500);
  digitalWrite(LED1,LED_OFF);
  delay(500);

  //LED2を点滅
  digitalWrite(LED2,LED_ON);
  delay(500);
  digitalWrite(LED2,LED_OFF);
  delay(500);

  //LED3を点滅
  digitalWrite(LED3,LED_ON);
  delay(500);
  digitalWrite(LED3,LED_OFF);
  delay(500);
  return;
}
