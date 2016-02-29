
/* 
  Code voor aansturing driver DRV8825 (stapmotor)
  Deze code betreft een testcode voor de driver
  
 */

#define resetPin 33  // reset voor driver
#define enablePin 31 // enable voor driver

#define STEPDIVIDER 1/32    //Specifies amount of steps before a full step (1 , 1/2, 1/4, 1/8, 1/16, 1/32)
#define STEPS 200           //Steps of the Stepper motor for one full rotation

#define DEGREES (float)(STEPS/STEPDIVIDER)/360

int directionPin = 35;      // richting
int stepperPin = 11;        // stap

void driverOn(){
 digitalWrite(enablePin, LOW);
}

void driverOff(){
 digitalWrite(enablePin, HIGH);
}

void driverReset(){
 digitalWrite(resetPin, LOW);
 delay(1000);
 digitalWrite(resetPin, HIGH);
}

void setup() {
 pinMode(directionPin, OUTPUT);
 pinMode(stepperPin, OUTPUT);

 pinMode(resetPin, OUTPUT);
 pinMode(enablePin, OUTPUT);

 driverReset();
 driverOn();

}

void steps(boolean dir,int steps){
 digitalWrite(directionPin,dir);
 delay(50);
 for(int i=0;i<steps;i++){
   digitalWrite(stepperPin, HIGH);
   delayMicroseconds(800);
   digitalWrite(stepperPin, LOW);
   delayMicroseconds(800);
 }
}

void loop(){
 driverOff();
 delay(5000);
 driverOn();

 steps(true,180*DEGREES);
}
