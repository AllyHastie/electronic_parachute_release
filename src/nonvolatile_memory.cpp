#include "nonvolatile_memory.h"

/******************************************************************************
Function Name: writeEEPROM
Reads data struct to ROM.
    Input: Data, startAddress
    Output: N/A
******************************************************************************/
void NVM :: writeEEPROM(DataNode data, int* startAddress)
{
    // initialises EEPROM
    EEPROM.begin(EEPROM_SIZE);

    if (*startAddress <= (EEPROM_SIZE - STRUCT_SIZE))
    {
        // initialises temporary vairables
        float tmp;
        int dataSize;

        // writes time in milliseconds to EEPROM
        EEPROM.writeInt(*startAddress, millis());
        *startAddress += sizeof(int);

        // writes state as integer to EEPROM
        switch(data.state)
        {
            case state :: STATE_ARMED:
                EEPROM.writeShort(*startAddress, 1);
                break;
            case state :: STATE_ASCENT:
                EEPROM.writeShort(*startAddress, 2);
                break;
            case state :: STATE_APOGEE:
                EEPROM.writeShort(*startAddress, 3);
                break;
            case state :: STATE_DESCENT:
                EEPROM.writeShort(*startAddress, 4);
                break;
            case state :: STATE_ERROR:
                EEPROM.writeShort(*startAddress, 0);
                break;
            default:
                EEPROM.writeShort(*startAddress, 0);

                
        }
        *startAddress += sizeof(short int);

        // writes acceleration and alititude to EEPROM
        for (int i = 0; i < NUM_FLOAT; i++)
        {
            switch(i)
            {
                case 0:
                    tmp = data.acceleration.x;
                    break;
                case 1:
                    tmp = data.acceleration.y;
                    break;
                case 2:
                    tmp = data.acceleration.z;
                    break;
                case 3:
                    tmp = data.altitude;
                    break;
            }

            // check for null and unset variables
            EEPROM.writeFloat(*startAddress, tmp);
            *startAddress += sizeof(float);
        }

        EEPROM.commit();
    }
    EEPROM.end();
}

/******************************************************************************
Function Name: readEEPROM
Reads all data in CSV format.
    Input: N/A
    Output: N/A
******************************************************************************/
void readEEPROM()
{
    // initialises start address as 0 to read from EEPROM
    int start = 0;

    // initialises EEPROM
    EEPROM.begin(EEPROM_SIZE);

    // writes header for data in CSV format
    Serial.println("Time (milliseconds);State;Acceleration (X);Acceleration (Y);Acceleration (Z);Altitude (m)");
    
    while (EEPROM.read(start) != 0)
    {
        for(int i = 0; i < NUM_VARIABLES; i++)
        {

            if(i == TIME_INDEX)
            {
                Serial.print(EEPROM.readInt(start));
                start += sizeof(int);
            }
            else if(i == STATE_INDEX)
            {
                int state = EEPROM.readShort(start);
                switch(state)
                {
                    case 1: 
                        Serial.print("ARMED");
                        break;
                    case 2: 
                        Serial.print("ASCENT");
                        break;
                    case 3: 
                        Serial.print("APOGEE");
                        break;
                    case 4: 
                        Serial.print("DESCENT");
                        break;
                    case 5: 
                        Serial.print("LANDED");
                        break;
                    case 0: 
                        Serial.print("ERROR");
                        break;
                }
                start += sizeof(short int);
            }
            else
            {
                Serial.print(EEPROM.readFloat(start));
                start += sizeof(float);
            }
            if(i < (NUM_VARIABLES-1))
            {
            Serial.print(';');
            }
        }
        Serial.println();
    }
}



/******************************************************************************
Function Name: clearEEPROM
Clears all data in EEPROM.
    Input: N/A
    Output: N/A
******************************************************************************/
void clearEEPROM()
{
    EEPROM.begin(EEPROM_SIZE);
    for (int i = 0 ; i < EEPROM_SIZE ; i++) 
    {
        EEPROM.write(i, 0);
    }
    EEPROM.end();
    
}