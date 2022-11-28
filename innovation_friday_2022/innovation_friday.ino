#include <CAN.h>
#include "CAN_recv.h"
#include "gesture.h"
#include "io_objs.h"

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CAN Receiver");
  can_begin();
}

void loop() {  
  can_recv(&frame);
  //frame_print(&frame);
  trigger(&frame);
}
