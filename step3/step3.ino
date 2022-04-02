//演習3
#include "enpitshield.h"
void setup() {
  Serial.begin(9600); //シリアル通信
  //ピンモードの初期設定
  pinMode(LED0, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  //プログラムが始まって時間開始
  int time = millis() / 1000;
  if (time % 10 == 0) { //timeが10で割れる値になったら出力
    Serial.println(time);
  }
  //LED0が500msで点灯中にLED3は２回250ms周期で点滅
  digitalWrite(LED0, LED_ON);
  delay(500);
  digitalWrite(LED3, LED_ON);
  delay(125);
  digitalWrite(LED3, LED_OFF);
  delay(125);
  digitalWrite(LED3, LED_ON);
  delay(125);
  digitalWrite(LED3, LED_OFF);
  delay(125);

  ////LED0が500msで消灯中にLED3は２回250ms周期で点滅
  digitalWrite(LED0, LED_OFF);
  delay(500);
  digitalWrite(LED3, LED_ON);
  delay(125);
  digitalWrite(LED3, LED_OFF);
  delay(125);
  digitalWrite(LED3, LED_ON);
  delay(125);
  digitalWrite(LED3, LED_OFF);
  delay(125);

  return;
}
