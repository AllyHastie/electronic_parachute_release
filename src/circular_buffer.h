#ifndef circular_buffer_h
#define circular_buffer_h

#include "global_variables.h"
#include "state_machine.h"

#define BUFFER_SIZE 5 // number of nodes stores in buffer


class circular_buffer
{
    private:
        int head = 0; 
        DataNode buffer[BUFFER_SIZE];
    public:
        void addData(float newAltitude, axis newAccel);
        DataNode getPrevNode();
        bool isEmpty(DataNode node);
};

#endif