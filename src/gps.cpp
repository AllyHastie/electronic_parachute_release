#include <TinyGPS++.h>
#include "gps.h"

/******************************************************************************
Function Name: initGPS
Initialise UART connection for GPS data transfer. 
    Input: N/A
    Output: int
        0 - No error
        1 - No reading and/or error
******************************************************************************/
int initGPS()
{
    ss.begin(GPSBaud);
    return isGPSValid();
}

/******************************************************************************
Function Name: getAlti
Read in altitude from GPS.
    Input: N/A
    Output: float altitude
******************************************************************************/
float getAlti()
{
    while(gps.altitude.isValid() == false)
    {
        while (ss.available()>0)
        {
            gps.encode(ss.read());
        }
    }

    // returns altitude in meters
    return gps.altitude.meters();
}

/******************************************************************************
Function Name: getCoord
Read in latitude and longitude of rocket.
    Input: N/A
    Output: class coord
******************************************************************************/
coord getCoord()
{
    while(gps.location.isValid() == false)
    {
        while (ss.available()>0)
        {
            gps.encode(ss.read());
        }
    }

    // latitude and longitude stored in struct
    coord coord = {gps.location.lat(), gps.location.lng()};
    
    // returns coord struct
    return coord;
}

/******************************************************************************
Function Name: isGPSValid
Validate working connection with GPS.
    Input: N/A
    Output: int
        0 - No error
        1 - No reading and/or error
******************************************************************************/
int isGPSValid()
{
    // parses GPS data until reading is validated or timesout
    unsigned long startTime = millis();

    // Timeout after 5 seconds
    while (millis() - startTime < 5000)  
    {
        while (ss.available() > 0)
        {
        if (gps.encode(ss.read()))
        {
            if (gps.location.isValid() && gps.date.isValid() && gps.time.isValid())
            {
            // received vaild GPS data
            return 0;
            }
        }
        }
    }
    // error flagged
    return 1; 
}
