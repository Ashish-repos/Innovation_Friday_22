// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <CAN.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CAN Sender");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... f0f6");

  CAN.beginExtendedPacket(0xf0f6);
  CAN.write(0xFF);
  CAN.write(0xFF);
  CAN.write(0xC0);
  CAN.write(0x10);
  CAN.endPacket();

  Serial.println("done");

  //delay(1000);

  // send extended packet: id is 29 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending extended packet ... f00f");

  CAN.beginExtendedPacket(0xf00f);
  CAN.write(0x15);
  CAN.write(0x21);
  CAN.endPacket();

  Serial.println("done");

  delay(1000);
}
