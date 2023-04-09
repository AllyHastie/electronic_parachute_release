#ifndef nonvolatile_memory_h
#define nonvolatile_memory_h

#include <EEPROM.h>
#include "global_variables.h"

#define EEPROM_SIZE 512 // EEPROM size
#define NUM_VARIABLES 6 // number of variables being read to EEPROM
#define TIME_INDEX 0 // index of time in struct
#define STATE_INDEX 1 // index of state in struct

/******************************************************************************
Data is stored in EEPROM in the following format:
    0 - (int) Time in milliseconds          - 4 bytes
      - (char) Semicolon delimiter          - 1 byte
    1 - (short int) State stored as int     - 2 bytes
      - (char) Semicolon delimiter          - 1 byte
    2 - (float) Acceleration on X axis      - 4 bytes
      - (char) Semicolon delimiter          - 1 byte
    3 - (float) Acceleration on Y axis      - 4 bytes
      - (char) Semicolon delimiter          - 1 byte
    4 - (float) Acceleration on Z axis      - 4 bytes
      - (char) Semicolon delimiter          - 1 byte
    5 - (float) Altitude stored in meters   - 4 bytes
      - (char) Semicolon delimiter          - 1 byte
                                            = 28 bytes 
The ESP32 is capable of story 512 bytes so ~18 data entries
******************************************************************************/
class NVM
{
    public:
        int startAddress = 0;
        void writeEEPROM(DataNode data, int* startAddress);
        void readEEPROM();
        void clearEEPROM();
};

#endif