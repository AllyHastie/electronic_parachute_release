#ifndef gps_h
#define gps_h

#include <TinyGPSPlus.h>
#include "SoftwareSerial.h"

// sets pinout on board
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;

// struct to store latitude, longitude and altitude
struct position {
    public:
        double latitude;
        double longitude;

};

// struct to store time
struct HHMMSS {
    public:
        int hour;
        int minute;
        int second;

};

// struct to store date
struct DDMMYY {
    public:
        int day;
        int month;
        int year;

};

// struct to store all GPS data
struct GPSData {
    public: 
        position location;
        DDMMYY date;
        HHMMSS time;
        float altitude;
};


class GPS {
    private:
        GPSData storeData();
        int isGPSValid();
    public: 
        int initGPS();
        GPSData readGPS();
};

#endif