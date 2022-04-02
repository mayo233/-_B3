//Tact switches   9-6
#include "enpitshield.h"
#include <MsTimer2.h>  //タイマー

static boolean output = LED_OFF; //LED0をOFFにしとく
static boolean output3 = LED_OFF;  //LED3をOFFにする
void flash() {
  //ここで点滅させるためにON OFFを繰り返す
  output = !output;

  //sw0が押されたらLED0を点滅させる
  if (digitalRead(TACTSW0) == TACTSW_ON) {
    digitalWrite(LED0, output);  //LED0を点滅
  }
  return;
}

void setup() {

  //pin設定
  pinMode(TACTSW0, INPUT);
  pinMode(LED0, OUTPUT);
  pinMode(LED3, OUTPUT);

  //set()メソッドで500msごとにflash()を実行するように登録
  MsTimer2::set(500, flash); //500msごとにオンオフ
  MsTimer2::start();  //これは割り込みを有効にする
}

//タイマ割り込みに関係なく実行する処理はここに書くと実行される
void loop() {
  //LED3を250msごとに点滅させる sw0を押している時だけ光る
  output3 = !output3;
  if (millis() % 250 == 0 && digitalRead(TACTSW0) == TACTSW_ON) {
    digitalWrite(LED3, output3);
  }

  return;

}
