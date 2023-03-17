#ifndef accelerometer_h
#define accelerometer_h

#include <Adafruit_ADXL343.h>

// initialises instance of ADXL343
// int parsed is board I2C address, needs to be changed
Adafruit_ADXL343 accel = Adafruit_ADXL343(12345); 

// object to store x, y and z axis acceleration
class axis {
    public: 
        float x;
        float y;
        float z;
};

// function prototypes
int initAccel();
int isAccelValid();
axis getAxisAccel();
int isAccelValid();

#endif