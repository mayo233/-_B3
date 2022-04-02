//Tact switches   9-５
#include "enpitshield.h"
#include <MsTimer2.h>

int val = 0; //タクトスイッチの状態を読み込む入力ピンの変数を初期化
int state = 0; //タクトスイッチの状態を覚えておく変数
int old_val = 0; //valの前の状態

void setup() {
  //TACTSEはスイッチのためINPUT LEDはOUTPUT
  pinMode(TACTSW0, INPUT);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  //スイッチ押下待ちの間に他のLEDを点滅させる
  MsTimer2::set(500, flash);
  MsTimer2::start();

}

void loop() {
  static boolean sw = false;  //swは０

  //スイッチが押されたらカウント
  if (chtsw(TACTSW0) == TACTSW_ON) {
    state = (state + 1) % 4; //スイッチ押した回数のあまりでLEDを光らせる
    //スイッチを押した回数によって光るLED
    if (state == 0) {
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

  }
  sw = !sw; //スイッチが離されたらvalもold_valも０

  return;
}

//スイッチの変化を検出する関数
boolean chtsw(byte dx) {
  boolean tsw = digitalRead(dx); //スイッチの状態
  while (tsw == digitalRead(dx)); //これだと待ち時間の間に何もできないらあまり良くない
  delay(20);  //チャタリング時間
  return !tsw;    //tswの逆を返す
}

//他のLEDを点滅させる関数 割り込み利用
void flash() {
  static boolean output = false;  //LEDの初期設定 off
  if (digitalRead(TACTSW0) == TACTSW_ON) {  //SW0が押されたら
    digitalWrite(LED3, output);  //LED3を点滅
  }
  output = !output;  //LEDの状態を逆にする
}
