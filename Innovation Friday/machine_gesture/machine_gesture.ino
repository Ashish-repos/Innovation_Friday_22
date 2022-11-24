#include "Arduino.h"
#include "machine_gesture.h"

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)  || defined(ARDUINO_attiny3217)
    delay(4000); // To be able to connect Serial monitor after reset or power up and before first print out. Do not wait for an attached Serial Monitor!
#endif

//MACHINE GESTURE IMPLEMENTATION
  FuelElevationIdle();
  delay(500);
  EngOverSpeed();
  delay(500);
  OilLevelTooLow();
  delay(500);
  FuelLevelTooLow();
  delay(500);
  FuelPressureTooLow();
  delay(500);
}


void loop() 
{

}
