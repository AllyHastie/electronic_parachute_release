#ifndef gps_h
#define gps_h

#include <TinyGPSPlus.h>
#include "SoftwareSerial.h"
#include "global_variables.h"

#define TIMEOUT 5e3 // 5 second timeout

/******************************************************************************
Sets pinout on board
******************************************************************************/
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;

class GPS {
    private:
        GPSData storeData();
        int isGPSValid();
    public: 
        int initGPS();
        GPSData readGPS();
};

#endif