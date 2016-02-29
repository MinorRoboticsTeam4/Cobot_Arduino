#include <Servo.h>



int relais[] = {39,41,42,43,44,45,46,47,48,49};

void displayRelaisTable(){
  Serial.println("-----------");
  Serial.println("Relais 1 | Relais 2 | Relais 3 | Relais 4 | Relais 5");  
  printDigital(digitalRead(relais[0]));Serial.print("       ");
  printDigital(digitalRead(relais[1]));Serial.print("       ");
  printDigital(digitalRead(relais[2]));Serial.print("       ");
  printDigital(digitalRead(relais[3]));Serial.print("       ");
  printDigital(digitalRead(relais[4]));Serial.print("       \r\n");
  Serial.println("Relais 6 | Relais 7 | Relais 8 | Relais 9 | Relais 10");
  printDigital(digitalRead(relais[5]));Serial.print("       ");
  printDigital(digitalRead(relais[6]));Serial.print("       ");
  printDigital(digitalRead(relais[7]));Serial.print("       ");
  printDigital(digitalRead(relais[8]));Serial.print("       ");
  printDigital(digitalRead(relais[9]));Serial.print("       \r\n");
}

void testRelais(){

  for(int i=0;i<10;++i){
    pinMode(relais[i], OUTPUT);
    digitalWrite(relais[i], HIGH);
  }

  Serial.println("Begin Test Relais");

  digitalWrite(relais[0],LOW);
  displayRelaisTable();
  delay(1000);

  for(int i=0;i<9;++i){
    digitalWrite(relais[i],HIGH);
    digitalWrite(relais[i+1],LOW);  
    displayRelaisTable();
    delay(1000);
  }

  digitalWrite(relais[9],HIGH);  
  displayRelaisTable();

  Serial.println("Finished Test");
}

void sweep(Servo servo,int sweep){

  int pos = 0;

  for (; pos <= sweep; pos += 1) { 
    servo.write(pos);             
    delay(15);                      
  }
  for (pos = sweep; pos >= 0; pos -= 1) {
    servo.write(pos);              
    delay(15);                       
  }

  Serial.println("Done");
}

void testServo(){
  Servo servoDispenser; 
  int servoDispenserPin = 10;

  Servo servoDropCatcher; 
  int servoDropCatcherPin = 12;

  servoDispenser.attach(servoDispenserPin);  
  servoDropCatcher.attach(servoDropCatcherPin); 

  Serial.println("Sweeping dispenser servo");
  sweep(servoDispenser,90);

  Serial.println("Sweeping drop catcher servo");
  sweep(servoDropCatcher,90);

  Serial.println("Finished Test");

}

#define resetPin 33  // reset voor driver
#define enablePin 31 // enable voor driver

#define STEPDIVIDER 1/32    //Specifies amount of steps before a full step (1 , 1/2, 1/4, 1/8, 1/16, 1/32)
#define STEPS 200           //Steps of the Stepper motor for one full rotation

#define DEGREES (float)(STEPS/STEPDIVIDER)/360

int directionPin = 35;      // richting
int stepperPin = 11;        // stap

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

void testStepper(){
 pinMode(directionPin, OUTPUT);
 pinMode(stepperPin, OUTPUT);

 pinMode(resetPin, OUTPUT);
 pinMode(enablePin, OUTPUT);

 driverReset();
 driverOn();
  
 steps(true,180*DEGREES);

 driverOff();

  Serial.println("Finished Test");

}
