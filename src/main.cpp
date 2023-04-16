#include <Arduino.h>
#include "global_variables.h"
#include "barometer.h"
#include "servo.h"

servo myservo;
barometer bmp280;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bmp280.Initialise_connection();
  
}

void loop() {
  bmp280.Reading_BMP();
  delay(1000);
  myservo.Initialise_latch();
  // put your setup code here, to run repeatedly:
}