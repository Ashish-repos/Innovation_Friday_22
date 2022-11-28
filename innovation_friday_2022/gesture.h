#ifndef GESTURE_H
#define GESTURE_H

  #include "machine_gesture.h"

  typedef struct{
    unsigned char rep_sec;
    unsigned char rep_num;
    unsigned long int last_time;
    int (*say_loud)();
  }gest;

  typedef struct{
    unsigned char rep_sec;
    unsigned char rep_num;
    unsigned long int last_time;
    int (*say_loud_load)(char);
  }gest_load;
   
  void speak(gest *b);
  void speak_load(gest_load *b, unsigned char l);

#endif /*GESTURE_H*/
