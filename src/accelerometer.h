#ifndef accelerometer_h
#define accelerometer_h

#include <Adafruit_ADXL343.h>
#include <Wire.h>
#include "global_variables.h"

class accelerometer{
    public:
        accelerometer(int address) : accelAddress(address) {};
        int initAccel();
        axis getAxisAccel();
        int isAccelValid();
        
    private:
        int accelAddress;
        Adafruit_ADXL343 accel = Adafruit_ADXL343(accelAddress); 
};


#endif