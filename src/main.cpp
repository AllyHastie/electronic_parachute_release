#include <Arduino.h>
#include "state_machine.h"

void setup() {
  // put your setup code here, to run once:
  state state = initState();
  getNextState(&state);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}