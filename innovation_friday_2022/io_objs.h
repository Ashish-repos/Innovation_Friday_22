#ifndef IO_OBJS_H
#define IO_OBJS_H

  #include "CAN_recv.h"
  #include "gesture.h"

  extern can_frame frame;
  
  extern gest eng_ovspd;
  extern gest eng_idle;
  extern gest oil_t_high;
  extern gest oil_t_low;
  extern gest fuel_p_high;
  extern gest fuel_p_low;
  extern gest_load mach_load;
  extern gest fuel_stop;

  /*
  eng_ovspd - 20,2
  EngIdle - 40
  EngOilTempHigh - 20
  EngOilTempLow - 20
  FuelPressureHigh - 30
  FuelPressureLow - 30
  MachLoad -  240
  EngFuelStop - 50
  */

#endif
