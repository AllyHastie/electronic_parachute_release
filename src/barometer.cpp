/******************************************************************************
Set up for BMP280
******************************************************************************/

#include "barometer.h"



/******************************************************************************
Function Name: Initialise_connection
Initialise I2C connection for barometer data transfer. 
    Input: N/A
    Output: N/A
******************************************************************************/
void barometer::Initialise_connection(){

  
  //Serial.begin(9600); 
  Wire.begin(); // Start the I2C interface
  bmp.begin(BMP280_ADDRESS); // Initialize the BMP280 sensor with the specified address
  Bmp = 1;
  BMP_test();
}
/******************************************************************************
Function Name: Reading_BMP
Function reads in 100 readings from the barometer and averages readings to 
reduce noise. Kalmann filter also completes this function but may be too 
complex for this application. 
    Input: N/A
    Output: float avgAlt
******************************************************************************/

void barometer::Reading_BMP(){
  //int i;
  //for(int r=0; r<=100; ++r){
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;
  float altitude = bmp.readAltitude(1013.25F); // define sea level for different locations

  // Print the temperature and pressure data to the serial monitor
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print(" *C, Pressure = ");
  Serial.print(pressure);
  Serial.print(" hPa, Altitude = ");
  Serial.print(altitude);
  Serial.println(" meters\n");
  delay(1000);
//   if (r==99){
//     i=100;
//   }
//   }
  //Serial.println(i);
}


/******************************************************************************
Function Name: XXXX
Read in parachute deployment threshold and determine deployment altitude.
    Input: int threshold, float armedAlt
    Output: float deployAlt
******************************************************************************/



/******************************************************************************
Function Name: BMP_test
Validate working connection with barometer.
    Input: N/A
    Output: int
        0 - No error
        1 - No reading and/or error
******************************************************************************/

void barometer::BMP_test(){
    if (Bmp==1){
        Serial.print("Success");
        Reading_BMP();
    }
    else{
        Serial.print("error");
    }
}