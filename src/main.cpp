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
#define READ_TIME 500 // milliseconds

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
  Serial.begin(115200);

  // initialise sensors
  ADXL343.initAccel();
  LM80_M39.initGPS();
  //initSwitch();

  // read in deployment altitude from switch
  deployAltitude = 2; //getSwitchState();

  if (deployAltitude == 0)
  {
    // open servo
  }
  else if (deployAltitude == 1)
  {
    // close servo
  }
  else
  {
    // check if servo is open. If open close (maybe)
    startAltitude = 0; // read in altitude 
    // clears EEPROM if altitude is set
    clearEEPROM();
  }
}

void loop() {
  // put your setup code here, to run repeatedly:

  if (deployAltitude == 0 || deployAltitude == 1)
  {
      readUser();
  }
  else if (deployAltitude == -1)
  {
    // if no reading on all sensors parachute is deployed after 1.5 minutes
    if(millis() - timeOfAscent > (ESTIMATE_FLIGHT_TIME * 60 * 1000))
    { 
      // open servo
    }
  }
  else
  {
    // read data from sensors. If non are valid set deployAltitude to -1.
    // fuse sensor data
    
    if (millis() - prevTime > 5000)
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