#include <MsTimer2.h>
#include "enpitshield.h"
#define TIMER_CYCLE 250  //250ごとにLED0を光らせる


void setup() {
  pinMode(LED3, OUTPUT); //led3を出力
  pinMode(LED1, OUTPUT); //led1を出力
  pinMode(TACTSW0, INPUT); //sw0
  pinMode(TACTSW1, INPUT); //sw1
  Serial.begin(9600);
  Led3_Init();     //led3を初期化
  Serial.println("cccc¥n");

  //attachInterrupt(digitalPinToInterrupt(TACTSW0),Led3_CountBlink, CHANGE);
  if (digitalRead(TACTSW0) == TACTSW_ON) {
    Serial.println("bbbbb¥n");
    MsTimer2::set(TIMER_CYCLE, Led3_Tick025); //led0を250msごとに点滅
    //if (digitalRead((TACTSW0) == TACTSW_ON)) {
    MsTimer2::start();  //タイマ割り込みをスタート
  }

  //}

  Led3_Endblink();
  Led3_Off();
}

void loop() {
}
