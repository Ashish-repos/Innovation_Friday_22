#include "gesture.h"

extern gest eng_ovspd;
extern gest estop;

void setup() {
  Serial.begin(9600);
}

void loop() {
  speak(&eng_ovspd);
  Serial.write(1);
  speak(&estop);
  Serial.write(3);
}
