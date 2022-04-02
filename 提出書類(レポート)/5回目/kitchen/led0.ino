#include "enpitshield.h"
boolean output;  //大域変数

//初期化 led0をオフにしとく
void Led0_Init() {
  output = LED_OFF;
}

//led0をon,offを繰り返す
void Led0_Tick05() {
  interrupts(); // 割り込み処理中も割り込みを許可 誤差を1%以内にする
  output = !output;
  digitalWrite(LED0, output);
}
