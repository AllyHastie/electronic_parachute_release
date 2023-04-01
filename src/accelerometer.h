#ifndef accelerometer_h
#define accelerometer_h

#include <Adafruit_ADXL343.h>
#include <Wire.h>
#include "global_variables.h"

int accelAddress = 53;

class accelerometer{
    private:
        int isAccelValid();
    public:
        int initAccel();
        axis getAxisAccel();
};


#endif