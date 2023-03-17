#ifndef gps_h
#define gps_h

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// sets pinout on board
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 4800;

// struct to store latitude and longitude
class coord {
    public: 
        float latitude;
        float longitude;
};

// instance of TinyGPSPlus
TinyGPSPlus gps;

// serial connection to GPS device
SoftwareSerial ss(RXPin, TXPin);

// function prototypes
int initGPS();
float getAlti();
coord getCoord();
int isGPSValid();

#endif