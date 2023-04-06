#ifndef nonvolatile_memory_h
#define nonvolatile_memory_h

#include <EEPROM.h>
#include "global_variables.h"

class NVM
{
    public:
        int startAddress = 0;
        void writeEEPROM(Data data, int* startAddress);
        void readEEPROM();
        void  clearEEPROM();
};

#endif