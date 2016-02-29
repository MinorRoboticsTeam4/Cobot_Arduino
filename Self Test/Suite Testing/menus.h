////////////Common Functions and Includes////////////
#include <Servo.h>
#include <AccelStepper.h>

void printDigital(int val){
  if(val){
    Serial.print("HIGH");
  }else{
    Serial.print("LOW ");
  }

}

#define ENABLEPIN 31
#define RESETPIN 33

void driverOn(){
 digitalWrite(ENABLEPIN, LOW);
}

void driverOff(){
 digitalWrite(ENABLEPIN, HIGH);
}

void driverReset(){
 digitalWrite(RESETPIN, LOW);
 delay(1000);
 digitalWrite(RESETPIN, HIGH);
}

/////////////////////////////////////////////////////

#include "actuator.h"
#include "nfc.h"
#include "sensor.h"
#include "system.h"


void menuMain(){
  Serial.println("Self Test Main Menu:");
  Serial.println("[1] Coffee System");
  Serial.println("[2] Components");

  Serial.println("Choose an option: ");

  //Wait for input
  while(1){
    if(Serial.available()){
      int choice = Serial.parseInt();
        switch(choice){
          case 1: coffeeSystemMenu();
          case 2: componentMenu();
          default: break;
        }
      break;
    }
  }

  
}

void coffeeSystemMenu(){
  Serial.println("Self Test Coffee System Menu:");
  Serial.println("[1] CoffeeMachine");
  Serial.println("[2] CupDispenser");
  Serial.println("[3] TurningWheel");
  Serial.println("[4] DropCatcher");
  Serial.println("[5] PresetTestAll");
  Serial.println("[6] Back");

  Serial.println("Choose an option: ");

  //Wait for input
  while(1){
    if(Serial.available()){
      int choice = Serial.parseInt();
        switch(choice){
          case 1: testCoffeeMachine();coffeeSystemMenu();
          case 2: testDispenser();coffeeSystemMenu();
          case 3: testTurningWheel();coffeeSystemMenu();
          case 4: coffeeSystemMenu();
          case 5: testCoffeeMachine();testDispenser();testTurningWheel();testDropCatcher();coffeeSystemMenu();
          case 6: menuMain();
          default: coffeeSystemMenu();
        }
      break;
    }
  }

}

void componentMenu(){
  Serial.println("Self Test Components Menu:");
  Serial.println("[1] Actuators");
//  Serial.println("[2] ArduinoBoard");
  Serial.println("[3] NFC");
  Serial.println("[4] Sensors");
  Serial.println("[5] PresetTestAll");
  Serial.println("[6] Back");

  Serial.println("Choose an option: ");

  //Wait for input
  while(1){
    if(Serial.available()){
      int choice = Serial.parseInt();
        switch(choice){
          case 1: actuatorMenu();
 //         case 2: arduinoBoardMenu();
          case 3: nfcMenu();
          case 4: sensorMenu();
          case 5: testRelais();testServo();testStepper();actuatorMenu();testNFC();testBattery();testBumperswitch();testLight();testUltrasoon();componentMenu();
          case 6: menuMain();
          default: componentMenu();
        }
    }
  }
}

void actuatorMenu(){
  Serial.println("Self Test Actuator Menu:");
  Serial.println("[1] Relais");
  Serial.println("[2] Servo");
  Serial.println("[3] Stepper");
  Serial.println("[4] PresetTestAll");
  Serial.println("[5] Back");

  Serial.println("Choose an option: ");

  //Wait for input
  while(1){
    if(Serial.available()){
      int choice = Serial.parseInt();
        switch(choice){
          case 1: testRelais();actuatorMenu();
          case 2: testServo();actuatorMenu();
          case 3: testStepper();actuatorMenu();
          case 4: testRelais();testServo();testStepper();actuatorMenu();
          case 5: componentMenu();
          default: actuatorMenu();
        }
    }
  }
}

void nfcMenu(){
  Serial.println("Self Test NFC Menu:");
  Serial.println("[1] read nfc card");
  Serial.println("[2] Back");

  Serial.println("Choose an option: ");

  //Wait for input
  while(1){
    if(Serial.available()){
      int choice = Serial.parseInt();
        switch(choice){
          case 1: testNFC();nfcMenu();
          case 2: componentMenu();
          default: nfcMenu();
        }
    }
  }
}

void sensorMenu(){
  Serial.println("Self Test Sensor Menu:");
  Serial.println("[1] Battery");
  Serial.println("[2] BumperSwitch");
  Serial.println("[3] Light");
  Serial.println("[4] Ultrasoon");
  Serial.println("[5] PresetTestAll");
  Serial.println("[6] Back");

  Serial.println("Choose an option: ");

  //Wait for input
  while(1){
    if(Serial.available()){
      int choice = Serial.parseInt();
        switch(choice){
          case 1: testBattery();sensorMenu();
          case 2: testBumperswitch();sensorMenu();
          case 3: testLight();sensorMenu();
          case 4: testUltrasoon();sensorMenu();
          case 5: testBattery();testBumperswitch();testLight();testUltrasoon();sensorMenu();
          case 6: componentMenu();
          default: sensorMenu();
        }
    }
  }
}
