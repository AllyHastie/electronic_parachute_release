#include "nonvolatile_memory.h"

/******************************************************************************
Function Name: writeEEPROM
Reads data struct to ROM.
    Input: Data, startAddress
    Output: N/A
******************************************************************************/
void NVM :: writeEEPROM(Data data, int* startAddress)
{
    int dataSize = sizeof(Data);

    EEPROM.begin(512);
    for (int i = 0; i < dataSize; i++) 
    {
        EEPROM.write(*startAddress + i, *((char*)&data + i));
        Serial.println(EEPROM.read(*startAddress + i));
    }
    
    *startAddress += dataSize;

    EEPROM.commit();
    EEPROM.end();
}


/******************************************************************************
Function Name: readEEPROM
Reads all data in CSV format.
    Input: N/A
    Output: N/A
******************************************************************************/
void NVM :: readEEPROM()
{
    int start = 0;
    int numData = EEPROM.length() / sizeof(Data);

    // print CSV header
    Serial.println("Data;Time;X;Y;Z;Altitude;State");

    for (int i = 0; i < numData; i++) {
        Data data;

        EEPROM.begin(EEPROM.length());
        for (int j = 0; j < sizeof(numData); j++) 
        {
        *((char*)&data + j) = EEPROM.read(startAddress + i * sizeof(Data) + j);
        }
        EEPROM.end();

        // prints data in CSV format
        Serial.print(data.date.day);
        Serial.print("/");
        Serial.print(data.date.month);
        Serial.print("/");
        Serial.print(data.date.year);
        Serial.print(";");

        Serial.print(data.time.hour);
        Serial.print(":");
        Serial.print(data.time.minute);
        Serial.print(":");
        Serial.print(data.time.second);
        Serial.print(";");

        Serial.print(data.acceleration.x);
        Serial.print(";");

        Serial.print(data.acceleration.y);
        Serial.print(";");

        Serial.print(data.acceleration.z);
        Serial.print(";");

        Serial.print(data.altitude);
        Serial.print(";");

        switch(data.state)
        {
            case state::STATE_ARMED:
                Serial.println("STATE_ARMED");
                break;
            case state::STATE_ASCENT:
                Serial.println("STATE_ASCENT");
                break;
            case state::STATE_APOGEE:
                Serial.println("STATE_APOGEE");
                break;
            case state::STATE_DESCENT:
                Serial.println("STATE_DESCENT");
                break;
            case state::STATE_LANDED:
                Serial.println("STATE_LANDED");
                break;
            case state::STATE_ERROR:
                Serial.println("STATE_ERROR");
                break;
        }
    }
}

/******************************************************************************
Function Name: clearEEPROM
Clears all data in EEPROM.
    Input: N/A
    Output: N/A
******************************************************************************/
void NVM :: clearEEPROM()
{
    for (int i = 0 ; i < EEPROM.length() ; i++) 
    {
        EEPROM.write(i, 0);
    }
}

