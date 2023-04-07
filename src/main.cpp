#include <Arduino.h>
#include "global_variables.h"
#include "nonvolatile_memory.h"
NVM nvm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Data data;
  data.acceleration = {89.6,-6.8,32.4};
  nvm.clearEEPROM();
  for (int i = 0; i < 3; i++)
  {
    data.altitude = i + 10;
    nvm.writeEEPROM(data, &nvm.startAddress);
    Serial.println();
    Serial.println();
  }

  nvm.readEEPROM();


}

void loop() {
  // put your setup code here, to run repeatedly:
}