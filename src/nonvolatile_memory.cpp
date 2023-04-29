#include "nonvolatile_memory.h"

/******************************************************************************
Function Name: writeEEPROM
Reads data struct to ROM.
    Input: Data, startAddress
    Output: N/A
******************************************************************************/
void NVM :: writeEEPROM(DataNode data, int* startAddress)
{
    if (*startAddress <= (EEPROM_SIZE - STRUCT_SIZE))
    {
        // initialises temporary vairables
        float tmp;

        // writes time in milliseconds to EEPROM
        eeprom_write_word((uint16_t*) *startAddress, (short int) (millis()/1000));
        *startAddress += WORD_SIZE;
        Serial.println(*startAddress);

        // writes state as integer to EEPROM
        switch(data.state)
        {
            case state :: STATE_ARMED:
                eeprom_write_byte((uint8_t*) *startAddress, 1);
                break;
            case state :: STATE_ASCENT:
                eeprom_write_byte((uint8_t*) *startAddress, 2);
                break;
            case state :: STATE_APOGEE:
                eeprom_write_byte((uint8_t*) *startAddress, 3);
                break;
            case state :: STATE_DESCENT:
                eeprom_write_byte((uint8_t*) *startAddress, 4);
                break;
            case state :: STATE_ERROR:
                eeprom_write_byte((uint8_t*) *startAddress, 0);
                break;
            default:
                eeprom_write_byte((uint8_t*) *startAddress, 0);

                
        }
        *startAddress += BYTE_SIZE;

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
            eeprom_write_word((uint16_t*) *startAddress, (short int) tmp);
            *startAddress += WORD_SIZE;
        }

    }
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

    // writes header for data in CSV format
    Serial.println("Time (seconds);State;Acceleration (X);Acceleration (Y);Acceleration (Z);Altitude (m)");
    while(start <= (EEPROM_SIZE - STRUCT_SIZE))
    {
        for(int i = 0; i < NUM_VARIABLES; i++)
        {

            if(i == TIME_INDEX)
            {
                short int tmp = eeprom_read_word((uint16_t*) start);
                Serial.print(tmp);
                start += WORD_SIZE;
            }
            else if(i == STATE_INDEX)
            {
                int state = eeprom_read_byte((uint8_t*) start);
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
                start += BYTE_SIZE;
            }
            else
            {
                short int tmp = eeprom_read_word((uint16_t*) start);
                Serial.print(tmp);
                start += WORD_SIZE;
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
    for (int i = 0 ; i < EEPROM_SIZE ; i++) 
    {
        eeprom_write_byte((uint8_t*) i, i);
    }
    
}



