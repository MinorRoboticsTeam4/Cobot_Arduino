#include <AccelStepper.h>                      
#include <math.h>

// Define pins and other stepper variables
#define STEP 11
#define DIR 35

#define ENABLEPIN 31
#define RESETPIN 33

#define STEPDIVIDER 1/32    //Specifies amount of steps before a full step (1 , 1/2, 1/4, 1/8, 1/16, 1/32)
#define STEPS 200           //Steps of the Stepper motor for one full rotation

#define DEGREES (float)(STEPS/STEPDIVIDER)/360

#define ANGLE (float)270                                  // angle the motor will turn
#define ACCEL (float)5000                                 // acceleration used (steps/second^2)
#define MAXSPEED (float)1000                              // max speed the motor will run (steps/second)


AccelStepper stepper(1, STEP, DIR);                     // initialize stepper

void driverReset(){
 digitalWrite(RESETPIN, LOW);
 delay(1000);
 digitalWrite(RESETPIN, HIGH);
}

void driverOn(){
 digitalWrite(ENABLEPIN, LOW);
}

void driverOff(){
 digitalWrite(ENABLEPIN, HIGH);
}

void setup()
{ 
    pinMode(ENABLEPIN, OUTPUT);
    pinMode(RESETPIN, OUTPUT); 

    Serial.begin(9600); 
    
    stepper.setMaxSpeed(MAXSPEED);                        // set max speed of stepper
    stepper.setAcceleration(ACCEL);                       // set accelaration of stepper
    stepper.setCurrentPosition(0);                        // set current postition

    driverReset();
    driverOff();
}

void loop(){

  delay(5000);
  TurnTable(180);
  Serial.println("Turned 180");
}
void TurnTable(float angle){

    int angleFlag = 0;
      while((angle - (stepper.currentPosition()/STEPS*360) <= 0))
      {
        angleFlag = 1;
        angle = angle + 360;
      }
      stepper.moveTo(angle*DEGREES);

      driverOn();
      while(stepper.distanceToGo())
         {
           stepper.run();
          }

      stepper.stop();
      driverOff();

      if(angleFlag == 1){
        stepper.setCurrentPosition(stepper.currentPosition()-(STEPS));
        Serial.println(stepper.currentPosition()/STEPS*360);
      }

}
