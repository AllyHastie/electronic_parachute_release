#ifndef linked_list_h
#define linked_list_h

#include "gps.h"
#include "accelerometer.h"

// struct to store all data
struct DataNode {
    public: 
        position location;
        DDMMYY date;
        HHMMSS time;
        axis acceleration;
        float altitude;  
        DataNode* prev;
        DataNode* next;

};

DataNode* head = NULL;
DataNode* tail = NULL;

void addData(position newLocation, DDMMYY newDate, HHMMSS newTime, float newAltitude, axis newAccel);
DataNode* getNthPrevData(int n);
DataNode* getPrevData();
#endif