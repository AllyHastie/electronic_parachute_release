#ifndef accelerometer_h
#define accelerometer_h

#include <Adafruit_ADXL343.h>

// object to store x, y and z axis acceleration
struct axis {
    public: 
        float x;
        float y;
        float z;
};

class accelerometer{
    private:
        int isAccelValid();
    public:
        int initAccel();
        axis getAxisAccel();
};


#endif