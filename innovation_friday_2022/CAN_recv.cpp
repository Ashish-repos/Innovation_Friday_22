#include "Arduino.h"
#include "CAN_recv.h"
#include "gesture.h"
#include "io_objs.h"
#include <CAN.h>

void can_begin()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  #if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)  || defined(ARDUINO_attiny3217)
    delay(4000); // To be able to connect Serial monitor after reset or power up and before first print out. Do not wait for an attached Serial Monitor!
  #endif
  
  CAN.setClockFrequency(8E6);
  if (!CAN.begin(250E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
  
}/*end of can_begin()*/

char can_recv(can_frame *rcv_frame)
{ 
  unsigned int canidfilt[] = {0xF003, 0xF001, 0xFEEE, 0xF004}; //{0xF004, 0xFEEE, 0xFEEF, 0xF003, 0xF001}; 
  unsigned int packetSize = CAN.parsePacket();
  unsigned long int canid;
  char i;
  
  rcv_frame->rcvd = 0;
  if (packetSize || CAN.packetId() != -1) { 
    canid = (long int) CAN.packetId();
    canid = (canid & 0x00FFFF00)>>8;
    for(i = 0; i < sizeof(canidfilt)/sizeof(canidfilt[0]); i++)
    {
      if(canidfilt[i] == canid)
      {
        rcv_frame->rcvd = 1;
        rcv_frame->can_id = (int)canid;
        rcv_frame->dlc = packetSize;
        if (CAN.packetExtended()) {
          rcv_frame->can_id_type = 1;
        }
        else {
          rcv_frame->can_id_type = 0;
        }
        for(i=0; i<packetSize; i++)
        {
          rcv_frame->can_byte[i] = (char)CAN.read();
        }
        return(1);
      }
    }
  }
  return(0); 
}/*end of can_recv()*/

void frame_print(can_frame *frame) {
  if (frame->rcvd == 1) {
    Serial.print(frame->can_id, HEX);
    Serial.print("   ");
    Serial.print(frame->dlc, HEX);
    Serial.print("   ");
    for(char i=0; i<frame->dlc; i++) {
      Serial.print(frame->can_byte[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
  frame->rcvd = 0;
}/*end of frame_print()*/

void trigger(can_frame *frame)
{
  if(frame->rcvd == 1) 
  {
    //Serial.println(frame->can_id,HEX);
  if (frame->can_id == 0xF001) /* Fuel Stop */
  {
    unsigned int fuel_stp = (unsigned int)((byte)(frame->can_byte[3] & 0b00110000)>> 4);
    //Serial.println(fuel_stp);
    if(fuel_stp == 1)
      {
      
      Serial.write(1);
      speak(&fuel_stop);
      //EngFuelStop();
      }
  }
  
  if (frame->can_id == 0xF004) /*Engine overspeed*/
  {
    unsigned int eng_spd = (unsigned int)(frame->can_byte[4]*256 + frame->can_byte[3]);
          if(eng_spd > 32000)
          {
            //Serial.println(eng_spd);
            //Serial.println("High");
      Serial.write(2);
            speak(&eng_ovspd);
          }
          if(eng_spd < 800)
          {
            //Serial.println(eng_spd);
            //Serial.println("low");
      Serial.write(3);
            speak(&eng_idle);
          }
  }
  
  if (frame->can_id == 0xFEEE) /*Engine oil temperature*/
  {
      unsigned int eng_temp = (frame->can_byte[3]*256 + frame->can_byte[2]);
      //Serial.println(eng_temp);
      
      if(eng_temp > 12000) //SEND 110*32
      {
      Serial.write(4);
      speak(&oil_t_high);
      }
      if(eng_temp < 10000) //SEND 10*32
      {
      Serial.write(5);
      speak(&oil_t_low);
      }
  }
  
  if (frame->can_id == 0xFEEF) /*Engine fuel pressure*/
  {
     unsigned int fuel_press = (unsigned int)(frame->can_byte[0]);
     if(fuel_press < 160)
     {
    Serial.write(6);
    speak(&fuel_p_low);
     }
     if(fuel_press > 3200)
     {
    Serial.write(7);
    speak(&fuel_p_high);
     }
  }
  
  if (frame->can_id == 0xF003) /*Machine load*/
  {
    unsigned int machine_load = (unsigned int)(frame->can_byte[2]);
    //Serial.println(frame->can_id);
    //Serial.println(machine_load);
     if(machine_load > 0 && machine_load <= 10)    /*10%*/
     {
    Serial.write(8);
    speak_load(&mach_load, (unsigned char)0);
     }
     if(machine_load > 11 && machine_load <= 20) /*20%*/
     {
    Serial.write(9);
    speak_load(&mach_load, (unsigned char)1);
     }
     if(machine_load > 21 && machine_load <= 30) /*30%*/
     {
    Serial.write(10);
    speak_load(&mach_load, (unsigned char)2);
     }
     if(machine_load > 31 && machine_load <= 40) /*40%*/
     {
    Serial.write(11);
    speak_load(&mach_load, (unsigned char)3);
     }
     if(machine_load > 41 && machine_load <= 50) /*50%*/
     {
    Serial.write(12);
    speak_load(&mach_load, (unsigned char)4);
     }
     if(machine_load > 51 && machine_load <= 60) /*60%*/
     {
    Serial.write(13);
    speak_load(&mach_load, (unsigned char)5);
     }
     if(machine_load > 61 && machine_load <= 70) /*70%*/
     {
    Serial.write(14);
    speak_load(&mach_load, (unsigned char)6);
     }
     if(machine_load > 71 && machine_load <= 80) /*80%*/
     {
    Serial.write(15);
    speak_load(&mach_load, (unsigned char)7);
     }
     if(machine_load > 81 && machine_load <= 90) /*90%*/
     {
    Serial.write(16);
    speak_load(&mach_load, (unsigned char)8);
     }
     if(machine_load > 91)                       /*100%*/
     {
    Serial.write(17);
    speak_load(&mach_load, (unsigned char)9);
     }
  }

  }
}
