#ifndef rom_h
#define rom_h

#include <Arduino.h>
#include <avr/eeprom.h>

#include "global_variables.h"

/******************************************************************************
Definitions
******************************************************************************/
#define EEPROM_SIZE 255 // EEPROM size
#define STRUCT_SIZE 11 // data used when storing struct (bytes)
#define NUM_VARIABLES 6 // number of variables being read to EEPROM
#define TIME_INDEX 0 // index of time in struct
#define STATE_INDEX 1 // index of state in struct
#define NUM_FLOAT 4 // number of floats being read to EEPROM
#define BYTE_SIZE 1
#define WORD_SIZE 2

/******************************************************************************
Data is stored in EEPROM in the following format:
    0 - (short int) Time in milliseconds        - 2 bytes
    1 - (byte) State stored as int              - 1 bytes
    2 - (short int) Acceleration on X axis      - 2 bytes
    3 - (short int) Acceleration on Y axis      - 2 bytes
    4 - (short int) Acceleration on Z axis      - 2 bytes
    5 - (short int) Altitude stored in meters   - 2 bytes
                                                = 11 bytes 
The ATtiny3217 is capable of story 256 bytes so ~23 data entries
******************************************************************************/

class NVM
{
  public:
    int startAddress = 0;
    void writeEEPROM(DataNode data, int* startAddress);
};

void readEEPROM();
void clearEEPROM();


#endif
