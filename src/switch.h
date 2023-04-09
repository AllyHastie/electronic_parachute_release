#ifndef switch_h
#define switch_h

#include <Arduino.h>

// defines switches pins
#define switchPin1 1
#define switchPin2 2
#define switchPin3 3
#define switchPin4 4


byte readSwitch();
int getSwitchState();

#endif