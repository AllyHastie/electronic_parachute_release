#ifndef barometer_h
#define barometer_h

#include <Adafruit_Sensor.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>

#define BMP280_ADDRESS 0x76 // Define the I2C address for BMP280 sensor






class barometer{
    private:
        Adafruit_BMP280 bmp;
        int Bmp=0;
    //within file
    public:
     void BMP_test();
     void Initialise_connection();
     void Reading_BMP();    //outside file
       
};



#endif