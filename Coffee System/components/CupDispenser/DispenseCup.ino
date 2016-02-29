// Written by Pieter van der Gaag
#include <Servo.h>

Servo servoDispense;  // create servo object to control a servo

void setup() {
  servoDispense.attach(10);  
  Serial.begin(9600);
}

int ADC_stabilize = 5;                                    // delay time to stabalize optic sensor
#define OPT_DISP_PIN A1                                   // pin of optic sensor at dispenser

//Function that reads optic optic sensor dispense place
int ReadOpticSensorDispense()
    {
      int value = 0;
      int sensor = analogRead(OPT_DISP_PIN);
      delay(ADC_stabilize);
      sensor = analogRead(OPT_DISP_PIN);
      delay(ADC_stabilize);

      if(sensor <= 750)
      {
        value = 1;                                      // Mug present
      }
      return value;
}


bool DispenseCup(){
  cupPresent = ReadOpticSensorDispense();
  
  if(cupPresent == false){
    Serial.println("Start dispense 135"); // print next position
    servoDispense.write(135);                   // sets the servo position to start position
    delay(1000);                          // waits for the servo to get there
    Serial.println("45");                 // print next position
    servoDispense.write(45);                    // sets the servo position to end position            
    delay(1000);                          // waits for the servo to get there
    Serial.println("135 end");            // print next position
    servoDispense.write(135);
    delay(500);
    cupPresent = ReadOpticSensorDispense();
    if (cupPresent == true) {
      return true;
      Serial.println("Dispense succeeded");
    }
  }
  else if(cupPresent == true) {
    Serial.println("Cup present");
    return false;
  }
}

void loop() {
  DispenseCup();

  while(1);
}


