#include "gesture.h"
#include "Arduino.h"

void speak(gest *b){
  if((millis()/1000 - b->last_time) >= b->rep_sec) {
    b->last_time = millis()/1000;
    for(char i=0; i<b->rep_num; i++){
      b->say_loud();
    }
  }
}

void speak_load(gest_load *b, unsigned char l){
  if((millis()/1000 - b->last_time) >= b->rep_sec) {
    b->last_time = millis()/1000;
    for(char i=0; i<b->rep_num; i++){
      b->say_loud_load(l);
    }
  }
}
