#ifndef circular_buffer_h
#define circular_buffer_h

#include "global_variables.h"
#include "nonvolatile_memory.h"
#include "state_machine.h"

// store in EEPROM every 8 seconds
#define readTime 8e3

/******************************************************************************
Definitions
******************************************************************************/
#define BUFFER_SIZE 5 // number of nodes stores in buffer


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
        bool isEmpty(DataNode node);
};

#endif