#ifndef servo_h
#define servo_h

#include <ESP32Servo.h>
#include <Adafruit_Sensor.h>

#define SERVO_PIN 4 // Define the pin for the servo motor

class servo{
    private:
        Servo myservo;
        
        // int Bmp=0;
    //within file
    public:
    //  void BMP_test();
      void Initialise_latch();
    //  void Reading_BMP();    //outside file
       
};



#endif