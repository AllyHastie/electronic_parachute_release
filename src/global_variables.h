#ifndef gloabl_variables_h
#define gloabl_variables_h

#include <stdint.h>
#include <SoftwareSerial.h>

extern int deployAltitude;
extern int timeOfAscent;

enum class state {
    STATE_ARMED, 
    STATE_ASCENT,
    STATE_APOGEE,
    STATE_DESCENT,
    STATE_LANDED,
    STATE_ERROR
};

// struct to store x, y and z axis acceleration
struct axis {
    public: 
        float x;
        float y;
        float z;
};

// struct to store latitude, longitude and altitude
// limited to 5 decimal places due to variable type
// having a 6th decimal place allows up to 0.11m precision, which is not neccessary for this application
struct position {
    public:
        float latitude;
        float longitude;

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
        uint16_t altitude;
};

// struct to store data
struct DataNode {
    public: 
        axis acceleration;
        float altitude;
        enum state state;

};

#endif