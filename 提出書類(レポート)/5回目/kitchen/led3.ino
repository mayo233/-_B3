#include "enpitshield.h"
boolean output3;  //大域変数
boolean output1;  //大域変数

int time = 30;
int count = 0;


//初期化 led3をオフにしとく
void Led3_Init() {
  output3 = LED_OFF;
}

//led3をon,offを繰り返す
void Led3_Tick025() {
  //if (digitalRead(TACTSW0) == TACTSW_ON) {
  Led3_CountBlink() ;
  interrupts(); // 割り込み処理中も割り込みを許可 誤差を1%以内にする
  output3 = !output3;
  digitalWrite(LED3, output3);
  /*
      interrupts(); // 割り込み処理中も割り込みを許可 誤差を1%以内にする
      output3 = !output3;
      digitalWrite(LED3, output3);
  */
  count++;
  if (count == 4) {
    Led3_Endblink();
    count = 0;

  }
  //}

}

//動作開始の知らせ
void Led3_CountBlink() {
  Serial.println("aaaaa¥n");
  //false=TRUE;
  //if (digitalRead(TACTSW0) == TACTSW_ON) {
  time--;
  Serial.println(time);
  if (time == 0) {
    Led3_Tick025();

  } else if ((time++ && time--) && digitalRead(TACTSW1) == TACTSW_ON) {
    output1 = !output1;
    digitalWrite(LED1, output1);
    time += 30;
  } else if ((time++ && time--) && digitalRead(TACTSW1) == TACTSW_ON && LED1 == LED_ON) {
    output1 = LED_OFF;
    time = 30;
    //}

  }
}

//点滅終了などの知らせ
void Led3_Endblink() {
  int led3time = 0;
  led3time++;
  if (led3time == 4) {
    Led3_Tick025();
  }
}

void Led3_Off() {
  output3 = LED_OFF;
}
