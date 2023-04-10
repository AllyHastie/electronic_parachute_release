#include <Arduino.h>
#include "global_variables.h"
#include "switch.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initSwitch();

}

void loop() {
  // put your setup code here, to run repeatedly:
  Serial.println(getSwitchState());
  delay(1e3);
  
}