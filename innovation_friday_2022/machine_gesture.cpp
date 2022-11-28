#include "Arduino.h"

#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_US_TI99.h"
#include "TalkieUtils.h"
#include "Vocab_Special.h"
#include "machine_gesture.h"

Talkie voice;

//Fuel Elevated Idle
int FuelElevationIdle()
{
  voice.say(sp5_FUEL);
  voice.say(sp5_ELEVATION);
  voice.say(sp5_IDLE);
  return 1;
}

/*    PGN_61444 SPN_190 */
// Engine Over Speed
int EngOverSpeed()
{
  voice.say(sp5_ENGINE);
  voice.say(sp5_OVERSPEED);
  return 2;
}
// Engine idle
int EngIdle()
{
  voice.say(sp5_ENGINE);
  voice.say(sp2_IS);
  voice.say(sp5_IDLE);
  delay(500);
  voice.say(sp5_GEAR);
  voice.say(sp5_UP);
  return 3;
}

// Engine Oil Level Too Low
int OilLevelTooLow()
{
  voice.say(sp4_OIL);
  voice.say(sp4_LEVEL);
  voice.say(sp4_TOO_LOW);
  return 4;
}

// Engine Fuel Level Too Low  
int FuelLevelTooLow()
{
  voice.say(sp4_FUEL);
  voice.say(sp4_LEVEL);
  voice.say(sp4_TOO_LOW);
  return 5;
}

// Emergency Shutdown
int EmerShutDown()
{
  voice.say(sp4_EMERGENCY);
  voice.say(sp2_SHUT);
  voice.say(sp5_DOWN);
  return 6;
}

//Engine Oil Temperature High
int EngOilTempHigh()
{
   voice.say(sp5_ENGINE);
   voice.say(sp4_OIL);
   voice.say(sp2_TEMPERATURE);
   voice.say(sp2_IS);
   voice.say(sp3_HIGH);
   return 7;
   
}
//Engine Oil Temperature Low
int EngOilTempLow()
{
   voice.say(sp5_ENGINE);
   voice.say(sp4_OIL);
   voice.say(sp2_TEMPERATURE);
   voice.say(sp2_IS);
   voice.say(sp3_LOW);
   return 8;
   
}

/* PGN_65263 SPN_94 Engine Fluid Delivery Pressure */
// Fuel Pressure High
int FuelPressureHigh()
{
   voice.say(sp4_FUEL);
   voice.say(sp4_PRESSURE);
   voice.say(spt_TOO);
   voice.say(sp3_HIGH);
   return 9;
   
}
// Engine Fuel Pressure Too Low  
int FuelPressureLow()
{
  voice.say(sp4_FUEL);
  voice.say(sp4_PRESSURE);
  voice.say(sp4_TOO_LOW);
  return 10;
}

/* Engine Load Percent*/
int MachLoad(unsigned char a)
{
   switch(a)
   {
      case 0:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_TEN);
         voice.say(sp3_PERCENT);
         break;
         
      case 1:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_TWENTY);
         voice.say(sp3_PERCENT);
         break;
         
      case 2:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_THIRTY);
         voice.say(sp3_PERCENT);
         break;
         
      case 3:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_FOURTY);
         voice.say(sp3_PERCENT);
         break;
         
      case 4:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_FIFTY);
         voice.say(sp3_PERCENT);
         break;
         
      case 5:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_SIXTY);
         voice.say(sp3_PERCENT);
         break;
         
      case 6:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_SEVENTY);
         voice.say(sp3_PERCENT);
         break;
         
      case 7:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_EIGHTY);
         voice.say(sp3_PERCENT);
         break;
         
      case 8:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_NINETY);
         voice.say(sp3_PERCENT);
         break;
         
      case 9:
         voice.say(sp2_MACHINE);
         voice.say(spt_LOAD);
         voice.say(sp2_AT);
         voice.say(sp3_HUNDRED);
         voice.say(sp3_PERCENT);
         break;
         
      default:
         break;
   }
}

/* PGN_61441 SPN_970 */
// Engine Fuel Stop
int EngFuelStop()
{
   voice.say(sp5_ENGINE);
   voice.say(sp5_FUEL);
   voice.say(sp3_STOP);
   return 11;
}
