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
        -1 - No reading and/or error
******************************************************************************/
int GPS::initGPS()
{
    gpsSerial.begin(GPSBaud);
    return isGPSValid();
}

/******************************************************************************
Function Name: readGPS
Reads GPS data.
    Input: N/A
    Output: GPSData Data
******************************************************************************/
GPSData GPS::readGPS()
{
    while (gpsSerial.available() > 0)
          if (gpsH.encode(gpsSerial.read()))

          
      if (millis() > 5000 && gpsH.charsProcessed() < 10)
        {
         while(true);
        }

    return storeData();
        
}

/******************************************************************************
Function Name: storeData
Stores data from GPS in a struct. 
    Input: N/A
    Output: GPSData data
******************************************************************************/

GPSData GPS::storeData()
{
GPSData data;
    if (gpsH.location.isValid())
    {
        data.location.latitude = gpsH.location.lat();
        data.location.longitude = gpsH.location.lng();
        data.altitude = gpsH.altitude.meters();
    }
    else
    {
        // invalid data
        data.location.latitude = -1;
        data.location.longitude = -1;
        data.altitude = -1;
    }

    if (gpsH.date.isValid())
    {
        data.date.day = gpsH.date.day();
        data.date.month = gpsH.date.month();
        data.date.year = gpsH.date.year();
    }
    else
    {
        // invalid data
        data.date.day = -1;
        data.date.month = -1;
        data.date.year = -1;
    }

    if (gpsH.time.isValid())
    {   
        data.time.hour = gpsH.time.hour();
        data.time.minute = gpsH.time.minute();
        data.time.second = gpsH.time.second();
    }
    else
    {
        // invalid data
        data.time.hour = -1;
        data.time.minute = -1;
        data.time.second = -1;
    }
return data;
}

/******************************************************************************
Function Name: isGPSValid
Validate working connection with GPS.
    Input: N/A
    Output: int
        0 - No error
        -1 - No reading and/or error
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
    return -1; 
}





