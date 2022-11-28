#ifndef CAN_RECV_H
#define CAN_RECV_H

  #include "Arduino.h"
  
  typedef struct {
    unsigned char rcvd;
    unsigned int can_id;
    unsigned char can_id_type;
    unsigned char dlc;
    unsigned char can_byte[8];
  } can_frame;
  
  extern char can_recv(can_frame *rcv_frame);
  extern void can_begin();
  extern void frame_print(can_frame *frame);
  extern void trigger(can_frame *frame);

#endif
