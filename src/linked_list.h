#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include "global_variables.h"
#include "state_machine.h"


class linked_list
{
    private:
        DataNode* head = NULL;
        DataNode* tail = NULL;
        DataNode* getPrevData();
        DataNode* getNthPrevData(int n);
    public:
        void addData(position newLocation, DDMMYY newDate, HHMMSS newTime, float newAltitude, axis newAccel);
        float getPrevAltitude();
        axis getPrevAccel();
        state getPrevState();
        float getAltitude();
        axis getAccel();
        state getState();
};

#endif