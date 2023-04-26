#include <Arduino.h>
#include "global_variables.h"
#include "accelerometer.h"
#include "gps.h"
#include "circular_buffer.h"
#include "nonvolatile_memory.h"
//#include "switch.h"

/******************************************************************************
Definitions
******************************************************************************/
#define ACCELEROMETER_ADDRESS 53
#define ESTIMATE_FLIGHT_TIME 1.5 // minutes
#define READ_INTERVAL 500 // milliseconds

/******************************************************************************
Function Prototypes
******************************************************************************/
void readUser();

/******************************************************************************
Initialise Variables
******************************************************************************/
int deployAltitude;
int startAltitude = 0;
int timeOfAscent = 0;
double prevTime = 0;

/******************************************************************************
Initialise Classes
******************************************************************************/
accelerometer ADXL343(ACCELEROMETER_ADDRESS);
GPS LM80_M39;
circular_buffer data;


void setup() {
  // put your setup code here, to run once:

  // read in deployment altitude from switch
  deployAltitude = 0; //getSwitchState();

  if (deployAltitude == 0)
  {
    Serial.begin(9600);
    // open servo
  }
  else if (deployAltitude == 1)
  {
    Serial.begin(9600);
    // close servo
  }
  else
  {
    // initialise peripherals
    ADXL343.initAccel();
    LM80_M39.initGPS();
    //initSwitch();

    // check if servo is open. If open close (maybe)

    startAltitude = 0; // read in altitude 
  }
}

void loop() {
  // put your setup code here, to run repeatedly:

  if (deployAltitude == 0 || deployAltitude == 1)
  {
      readUser();
  }
  else
  {
    // validates readings from sensors
    int validGPS = LM80_M39.isGPSValid();
    // if GPS and barometer are not reading any data
    if(validGPS == -1)
    {
      // if no reading on all sensors parachute is deployed after estimate flight time
      if(millis() - timeOfAscent > (ESTIMATE_FLIGHT_TIME * 60 * 1000))
      { 
        // open servo
      }
    }
    else if (millis() - prevTime > READ_INTERVAL)
    {
      data.addData(LM80_M39.getAltitude(), ADXL343.getAxisAccel());
      prevTime = millis();
    }
    
  }

}

/******************************************************************************
Function Name: readUser
Reads in user command from serial port and either prints EEPROM or clears
EEPROM. 
    Input: N/A
    Output: N/A
******************************************************************************/
void readUser()
{
  String incomingData = Serial.readString();
    if(incomingData!= "")
    {
      if (incomingData == "read")
      {
        Serial.println("Reading from EEPROM...");
        Serial.println();
        readEEPROM();
        Serial.println();
      }
      else if (incomingData == "clear")
      {
        Serial.println("Clearing EEPROM...");
        clearEEPROM();
        Serial.println("Complete");
        Serial.println();
      }
      else
      {
        Serial.println("Unknown command. Please enter: ");
        Serial.println("    read  - to read data from EEPROM");
        Serial.println("    clear - to clear data in EEPROM");
        Serial.println();
      }
    }
}