#include "servo.h"

void servo::Initialise_latch(){
myservo.attach(SERVO_PIN); 

  delay(1000);
  myservo.write(0); // rotate the servo to 0 degrees
  delay(1000);
  myservo.write(90); // rotate the servo to 180 degrees
  delay(1000);
  myservo.write(180); // rotate the servo to 360 degrees
  delay(1000); 
  
}