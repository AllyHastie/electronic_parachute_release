#ifndef circular_buffer_h
#define circular_buffer_h

#include "global_variables.h"
#include "nonvolatile_memory.h"
#include "state_machine.h"

/******************************************************************************
Definitions
******************************************************************************/
// store in EEPROM every 6 seconds
// based on 2 minute flight time
// time / number of writes to EEPROM
// [120, 150] / 23 = [5.21, 6.52]
#define readTime 6 // seconds

#define BUFFER_SIZE 5 // number of nodes stores in buffer

#include "SoftwareSerial.h"

class circular_buffer
{
    private:
        int head = 0; 
        int prevStore = 0;
        DataNode buffer[BUFFER_SIZE];
        NVM nvm;
    public:
        void addData(float newAltitude, axis newAccel);
        DataNode getPrevNode();
        float getNthPrevAltitude(int n);
        bool isEmpty(DataNode node);
};

void printData(DataNode data);

#endif