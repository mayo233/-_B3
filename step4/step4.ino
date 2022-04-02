//Tact switches   9-4
#include "enpitshield.h"

int val = 0; //タクトスイッチの状態を読み込む入力ピンの変数を初期化
int state = 0; //タクトスイッチの状態を覚えておく変数
int old_val = 0; //valの前の状態

void setup() {
  //TACTSWはスイッチのためINPUT LEDはOUTPUT
  pinMode(TACTSW0, INPUT);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop() {
  val = digitalRead(TACTSW0); //SW0がONかOFFか判定

  //スイッチが押されたらカウント
  if (val == HIGH && old_val == LOW) {
    state = (state + 1) % 4; //スイッチ押した回数のあまりでLEDを光らせる
    delay(1000);  //微調整
  }
  old_val = val;  //スイッチが離されたらvalもold_valも０
  
  //スイッチを押した回数によって光るLED
  if(state == 0 && val==HIGH) {
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
  }
  else if (state == 1) {
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  } else if (state == 2) {
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  } else if (state == 3) {
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }
  return;
}
