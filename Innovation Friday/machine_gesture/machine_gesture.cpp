#include "Arduino.h"

#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "TalkieUtils.h"
#include "Vocab_Special.h"
#include "machine_gesture.h"

Talkie voice;

int FuelElevationIdle()
{
  voice.say(sp5_FUEL);
  voice.say(sp5_ELEVATION);
  voice.say(sp5_IDLE);
  return 1;
}

int EngOverSpeed()
{
  voice.say(sp5_ENGINE);
  voice.say(sp5_OVERSPEED);
  return 1;
}
  
int OilLevelTooLow()
{
  voice.say(sp4_OIL);
  voice.say(sp4_LEVEL);
  voice.say(sp4_TOO_LOW);
  return 1;
}
  
int FuelLevelTooLow()
{
  voice.say(sp4_FUEL);
  voice.say(sp4_LEVEL);
  voice.say(sp4_TOO_LOW);
  return 1;
}
  
int FuelPressureTooLow()
{
  voice.say(sp4_FUEL);
  voice.say(sp4_PRESSURE);
  voice.say(sp4_TOO_LOW);
  return 1;
}
  
