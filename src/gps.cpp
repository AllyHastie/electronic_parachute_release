#include <TinyGPS++.h>
#include "gps.h"

/******************************************************************************
Function Name: initGPS
Initialise UART connection for GPS data transfer. 
    Input: N/A
    Output: N/A
******************************************************************************/
void initGPS()
{
    ss.begin(GPSBaud);
}

/******************************************************************************
Function Name: XXXX
Read in altitude from GPS.
    Input: N/A
    Output: float altitude
******************************************************************************/


/******************************************************************************
Function Name: XXXX
Validate working connection with GPS.
    Input: N/A
    Output: boolean
        0 - No error
        1 - No reading and/or error
******************************************************************************/