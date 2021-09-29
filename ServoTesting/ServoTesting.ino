// Author: Masood Ahmed 
// Logic:    1) Import a Servo Library
//           2) Define a Servo Object
//           3) Define a pin to attach the servo
//           4) initialize an angle
//           5) Test the servo by object.write(angle) to see if it moves or not
//           6) ********** Happy Coding :) ****************


#include <Servo.h>

// Creating a Servo object called servotest
Servo servoTest;

// Define the servo pin:
#define servoPin 9
  
// Create a variable to store the servo position:
int angle = 0;


void setup() {
    // Attach the Servo variable to a pin:
    servoTest.attach(servoPin);
  }
  
void loop() {
  
    // Tell the servo to go to a particular angle:
    servoTest.write(90);
    delay(1000);
    servoTest.write(180);
    delay(1000);
    servoTest.write(0);
    delay(1000);
    
    // Sweep from 0 to 180 degrees:
    for (angle = 0; angle <= 180; angle++) {
      servoTest.write(angle);
      delay(15);
    }

  

  // Sweeping back from 180 to 0 degrees:
  for (angle = 180; angle >= 0; angle--) {
    servoTest.write(angle);
    delay(30);
  }
  
  delay(1000);
}
