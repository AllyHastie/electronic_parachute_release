#ifndef gloabl_variables_h
#define gloabl_variables_h

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

// struct to store all data in linked list
struct DataNode {
    public: 
        position location;
        DDMMYY date;
        HHMMSS time;
        axis acceleration;
        float altitude;
        enum state state;
        DataNode* prev;
        DataNode* next;

};

#endif