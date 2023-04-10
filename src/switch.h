#ifndef switch_h
#define switch_h

#include <Arduino.h>

// allows 30 seconds for switch to be set
#define totalTime 3e4

// when 5 seconds of time remaining LED blinks quicker
#define fastBlinkTime 5e3

#define LED 5

// defines switches pins
// default data
#define switchPin1 1
#define switchPin2 2
#define switchPin3 3
#define switchPin4 4

void initSwitch();
byte readSwitch();
void blinkLED();
int getSwitchState();

#endif