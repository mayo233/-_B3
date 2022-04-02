//sample program :Blink LED0,LED2
#include "enpitshield.h"

//LED lamps port number
#define LED0 5
#define LED2 10
#define LED0_ON HIGH
#define LED_OFF LOW

void setup(){
  Serial.begin(9600);
  //ピンモードの初期設定
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {

  int light, repeat,count=0;

  //for (light = 0; light <= 10; light++) {
    for (repeat = 0; repeat < 50; repeat++) {
      digitalWrite(LED0,LED_ON);
      delay(500);
      analogWrite(LED3,250*0.01);
      delay(125);
      count++;
      if(count==10){
        Serial.println(LED3,DEC);   
        count=0;     
      }
    }
  //}
  return;
}
