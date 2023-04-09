/******************************************************************************
Set up for BMP280
******************************************************************************/


#include <Adafruit_Sensor.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

/******************************************************************************
Function Name: XXXX
Initialise I2C connection for barometer data transfer. 
    Input: N/A
    Output: N/A
******************************************************************************/



/******************************************************************************
Function Name: XXXX
Function reads in 100 readings from the barometer and averages readings to 
reduce noise. Kalmann filter also completes this function but may be too 
complex for this application. 
    Input: N/A
    Output: float avgAlt
******************************************************************************/



/******************************************************************************
Function Name: XXXX
Read in parachute deployment threshold and determine deployment altitude.
    Input: int threshold, float armedAlt
    Output: float deployAlt
******************************************************************************/



/******************************************************************************
Function Name: XXXX
Validate working connection with barometer.
    Input: N/A
    Output: int
        0 - No error
        -1 - No reading and/or error
******************************************************************************/