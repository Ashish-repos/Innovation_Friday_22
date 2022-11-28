#include "CAN_recv.h"
#include "gesture.h"

can_frame frame = {0,0,0,0,{0,0,0,0,0,0,0,0}};
gest eng_ovspd        = {20,2,0,&EngOverSpeed};      
gest eng_idle         = {40,1,0,&EngIdle};
gest oil_t_high       = {20,1,0,&EngOilTempHigh};
gest oil_t_low        = {20,1,0,&EngOilTempLow};
gest fuel_p_high      = {30,1,0,&FuelPressureHigh};
gest fuel_p_low       = {30,1,0,&FuelPressureLow};
gest_load mach_load   = {30,1,0,&MachLoad};
gest fuel_stop        = {30,1,0,&EngFuelStop};
