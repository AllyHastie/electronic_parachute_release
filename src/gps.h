#ifndef gps_h
#define gps_h

#include <TinyGPSPlus.h>
#include "SoftwareSerial.h"

// sets pinout on board
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;

// struct to store latitude and longitude
class coord {
    public: 
        double latitude;
        double longitude;
};


class GPS {
    public: 
        // function prototypes
        int initGPS();
        float getAlti();
        coord getCoord();
        int isGPSValid();
        int getHHMMSSCC();
        int getSatellites();
};

#endif