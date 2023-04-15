#ifndef state_machine_h
#define state_machine_h

#include <Arduino.h>
#include "global_variables.h"

// distance required to determine state change
#define SC_DISTANCE 5 // meters

int getNextState (DataNode* prevState, DataNode* state, float nthPrevAltitude);

#endif