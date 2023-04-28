/******************************************************************************
Setup for ADXL343
******************************************************************************/
#include "accelerometer.h"

/******************************************************************************
Function Name: initAccel
Initialise I2C connection for accelerometer data transfer. 
    Input: N/A
    Output: int
        0 - No error
        -1 - No reading and/or error
******************************************************************************/
int accelerometer::initAccel()
{
    // initiates I2C connection
    Wire.begin();

    // initialises ADXL343 accelerometer
    if(!accel.begin())
    {
        // if not found error flag set
        return -1;
    }
    // sets range to +/- 16G
    accel.setRange(ADXL343_RANGE_16_G);
    // sets data rate to 100Hz
    accel.setDataRate(ADXL343_DATARATE_100_HZ);
    return 0; 

}

/******************************************************************************
Function Name: getAxisAccel
Read in acceleration on multiple 
    Input: N/A
    Output: axis
******************************************************************************/
axis accelerometer::getAxisAccel()
{
    // reads accelerometer data
    sensors_event_t event;
    accel.getEvent(&event);

    // stores accelerometer data in class axis
    axis axis = {-1, -1, -1};
    if(isAccelValid() != -1)
    {
        axis = {event.acceleration.x, event.acceleration.y, event.acceleration.z};
    }
    // returns axis
    return axis;
}

/******************************************************************************
Function Name: isAccelValid
Validate working connection with accelerometer.
    Input: N/A
    Output: int
        0 - No error
        -1 - No reading and/or error
******************************************************************************/
int accelerometer::isAccelValid()
{
     // tests getRange() to confirm data is being transmitted
     if (accel.getRange()!=0)
     {
         // data is being transmitted
         return 0;
     }
     // error flag set
     return -1;
 }