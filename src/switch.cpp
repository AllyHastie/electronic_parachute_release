#include "switch.h"

/******************************************************************************
Function Name: initSwitch
Initialises switch on pins.
    Input: N/A
    Output: N/A
******************************************************************************/
void initSwitch()
{
    // initialises all pins for switch as input
    pinMode(switchPin1, INPUT);
    pinMode(switchPin2, INPUT);
    pinMode(switchPin3, INPUT);
    pinMode(switchPin4, INPUT);

    // initialises LED pin as output
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
}

/******************************************************************************
Function Name: readSwitch
Reads the position of the switch.
    Input: N/A
    Output: byte
******************************************************************************/

byte readSwitch()
{
    // reads value from pins and stores in byte
    byte switchVal = (digitalRead(switchPin1) << 3 ) | (digitalRead(switchPin2) << 2 ) | (digitalRead(switchPin3) << 1 ) | (digitalRead(switchPin4) << 0 );
    return switchVal;
}

/******************************************************************************
Function Name: blinkLED
Users are given 1 minute to set switch to preferred position. LED blinks 
during this time, indicating time left by speed of the blinks.
    Input: N/A
    Output: N/A
******************************************************************************/
void blinkLED()
{
    int startTime = millis();
    while(millis() - startTime < totalTime)
    {
        // turn on LED
        digitalWrite(LED, HIGH);
        delay(200);

        // turn off LED
        digitalWrite(LED, LOW);
        if(millis() - startTime >= (totalTime - fastBlinkTime))
        {
            delay(50);
        }
        else
        {
            delay(800);
        }
    }
}

/******************************************************************************
Function Name: getSwitchState
Returns altitude based on switch position. Switch position 0 or 1 is used for 
setup. Switch position 2 - F is returns altitude deployment threshold.
    Input: N/A
    Output: altitude
******************************************************************************/
int getSwitchState()
{
    blinkLED();
    byte switchVal = readSwitch();
    switch(switchVal)
    {
        // 0 will be used to open latch
        case 0x00:
            return 0;
        // 1 will be used to close latch
        case 0x01:
            return 1;
        // other cases determine altitude in meters
        case 0x02:
            return 50;
        case 0x03:
            return 75;
        case 0x04:
            return 100;
        case 0x05:
            return 125;
        case 0x06:
            return 150;
        case 0x07:
            return 175;
        case 0x08:
            return 200;
        case 0x09:
            return 250;
        case 0x0A:
            return 300;
        case 0x0B:
            return 350;
        case 0x0C:
            return 400;
        case 0x0D:
            return 450;
        case 0x0E:
            return 500;
        case 0x0F:
            return 550;
    }
    // error flag set
    return -1; 
}