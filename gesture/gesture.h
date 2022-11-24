#ifndef GESTURE_H
#define GESTURE_H

void say(char a);

typedef struct{
  //function pointer
  char rep_sec;
  char rep_num;
  long int last_time;
  void (*say_loud) (char);
}gest;

void speak(gest *b);

static gest eng_ovspd = {30,3,0,&say};  //change this say to speacific talkie function
static gest estop = {40,5,0,&say};      //change this say to speacific talkie function

#endif /*GESTURE_H*/
