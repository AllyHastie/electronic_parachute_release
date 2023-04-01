#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include "global_variables.h"
#include "state_machine.h"


class linked_list
{
    private:
        int dataStored = 5;
        DataNode* head = NULL;
        DataNode* tail = NULL;
        DataNode* getNthPrevData(int n);
    public:
        void addData(float newAltitude, axis newAccel);
        float getPrevAltitude();
        axis getPrevAccel();
        state getPrevState();
        float getAltitude();
        axis getAccel();
        state getState();
        DataNode* getPrevData();
};

#endif