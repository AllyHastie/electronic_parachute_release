#include "gps.h"

// instance of TinyGPSPlus
TinyGPSPlus gpsH;
SoftwareSerial gpsSerial(RXPin, TXPin);

/******************************************************************************
Function Name: initGPS
Initialise UART connection for GPS data transfer. 
    Input: N/A
    Output: int
        0 - No error
        1 - No reading and/or error
******************************************************************************/
int GPS::initGPS()
{
    gpsSerial.begin(GPSBaud);
    return isGPSValid();
}

int GPS::getHHMMSSCC()
{
    while (gpsSerial.available()>0)
    {
        gpsH.encode(gpsSerial.read());
    }
    // returns altitude in meters
    return gpsH.time.value();
}

int GPS::getSatellites()
{
    while (gpsSerial.available()>0)
    {
        gpsH.encode(gpsSerial.read());
    }
    // returns altitude in meters
    return gpsH.satellites.value();
}

/******************************************************************************
Function Name: getAlti
Read in altitude from GPS.
    Input: N/A
    Output: float altitude
******************************************************************************/
float GPS::getAlti()
{
    while (gpsSerial.available()>0)
    {
        gpsH.encode(gpsSerial.read());
    }
    // returns altitude in meters
    return gpsH.altitude.meters();
}

/******************************************************************************
Function Name: getCoord
Read in latitude and longitude of rocket.
    Input: N/A
    Output: class coord
******************************************************************************/
coord GPS::getCoord()
{
    while(gpsH.location.isValid() == false)
    {
        while (gpsSerial.available()>0)
        {
            gpsH.encode(gpsSerial.read());
        }
    }

    // latitude and longitude stored in struct
    coord coord = {gpsH.location.lat(), gpsH.location.lng()};
    
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
int GPS::isGPSValid()
{
    // parses GPS data until reading is validated or timesout
    unsigned long startTime = millis();

    // Timeout after 5 seconds
    while (millis() - startTime < 5000)  
    {
        while (gpsSerial.available() > 0)
        {
        if (gpsH.encode(gpsSerial.read()))
        {
            if (gpsH.location.isValid() && gpsH.date.isValid() && gpsH.time.isValid())
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



