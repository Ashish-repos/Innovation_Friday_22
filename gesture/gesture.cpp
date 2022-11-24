#include "gesture.h"
#include "Arduino.h"

void say(char a){
  Serial.write(a);
}

/*
 * CALL SPEAK IF DETECTED AN ERROR FROM THE CAN DATA FRAME
 * SPEAK SCHEDULES OUTPUT AT A SPECIFIC REPEAT INTERVAL GIVEN IN 
 *                       STRUCTURE BUFF.rep_sec
 * SPEAK REPEATES MULTIPLE TIMES AS GIVEN IN
 *                       STRUCTURE BUFF.rep_num
 *                       
 * Changes - when ever error held in PGN is detected -
 * call speak but also write the specific byte using Serial.write()
 * This serial write helps the python script to generate the gTTS voice
*/


void speak(gest *b){
  if((millis()/1000 - b->last_time) >= b->rep_sec) {
    b->last_time = millis()/1000;
    for(char i=0; i<b->rep_num; i++){
      b->say_loud(b->rep_num); //just call... 
    }
  }
}
