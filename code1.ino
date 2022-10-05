// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 4;
const int stepPin = 2;
 int enPin = 8;

// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // set the maximum speed, acceleration factor,
  // initial speed and the target position
  pinMode( enPin ,OUTPUT);
  digitalWrite( enPin , LOW);

 // myStepper.setCurrent(0);
  
 // myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(2000);
  myStepper.setSpeed(1000);
  myStepper.moveTo(1600);
  
}

void loop() {
  // Change direction once the motor reaches target position
  if (myStepper.distanceToGo() == 0) 
    myStepper.moveTo(-myStepper.currentPosition());

  // Move the motor one step
  myStepper.run();
}
