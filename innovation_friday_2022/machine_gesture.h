#include "Arduino.h"
#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "TalkieUtils.h"
#include "Vocab_Special.h"

// Fuel Elevation Idle
int FuelElevationIdle();

//Engine Over speed
int EngOverSpeed();
int EngIdle();

//Low Oil Level
int OilLevelTooLow();

//Low Fuel Level
int FuelLevelTooLow();

//Emergency Shut Down
int EmerShutDown();

//Engine Oil Temperature
int EngOilTempHigh();
int EngOilTempLow();

//Engine Fluid Delivery Pressure
int FuelPressureHigh();
int FuelPressureLow();

/* Engine Load Percent*/
int MachLoad(unsigned char);

// Engine Fuel Stop
int EngFuelStop();
