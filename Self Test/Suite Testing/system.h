void showMachineMenu(){
  Serial.println("Kies 1 voor Koffie");
  Serial.println("Kies 2 voor Cappuchino");
  Serial.println("Kies 3 voor Espresso");
  Serial.println("Kies 4 voor Cafe au Lait");
  Serial.println("Kies 5 voor Wiener Melange");
  Serial.println("Kies 6 voor Dubbele Espresso");
  Serial.println("Kies 7 voor Cafe Mocca");
  Serial.println("Kies 8 voor Cafe Macchiato");
  Serial.println("Kies 9 voor Esprechoc");
  Serial.println("Kies 10 voor Hot Chocolate");
  Serial.println();
  Serial.println("Welke drank wilt u?");
  Serial.println();
}

int ReadOpticSensorMachine()
    {
      int value = 0;
      int sensor = analogRead(A0);
      delay(5);
      sensor = analogRead(A0);
      delay(5);

      if(sensor <= 750)
      {
        value = 1;                                      // Mug present
      }
       return value;
}

void testCoffeeMachine(){
/* 
  Code voor aansturing relais voor de koffiemachine
  39 = hot chocolate      (0)
  41 = wiener melange     (1)
  42 = café mocca         (2)
  43 = café au lait       (3)
  44 = koffie zwart       (4)
  45 = esprechoc          (5)
  46 = dubbele espresso   (6)
  47 = cappuchino         (7)
  48 = café magiato       (8)
  49 = espresso           (9)

 */

  int koffiePin[] = {39,41,42,43,44,45,46,47,48,49};
  int delaytime;
  int value;


  pinMode(koffiePin[0], OUTPUT);
  pinMode(koffiePin[1], OUTPUT);
  pinMode(koffiePin[2], OUTPUT);
  pinMode(koffiePin[3], OUTPUT);
  pinMode(koffiePin[4], OUTPUT);
  pinMode(koffiePin[5], OUTPUT);
  pinMode(koffiePin[6], OUTPUT);
  pinMode(koffiePin[7], OUTPUT);
  pinMode(koffiePin[8], OUTPUT);
  pinMode(koffiePin[9], OUTPUT);

  for(int i=0; i<10; i++){
    digitalWrite(koffiePin[i], HIGH);
  }

  delaytime = 500; // De tijd dat een knop is ingedrukt

  while(!ReadOpticSensorMachine()){
      Serial.println("Plaats een beker/mok onder de koffiemachine");
      delay(1000);
  }
  showMachineMenu();
  


  //Wait for input
  while(!Serial.available()){}
    value = Serial.parseInt();
    Serial.print("U heeft gekozen voor keuze: ");
    Serial.println(value);
      switch(value){
      case 1: 
        Serial.println("Koffie wordt gemaakt");
        digitalWrite(koffiePin[4], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[4], HIGH);
        break;
      case 2: 
        Serial.println("Cappuchino wordt gemaakt");
        digitalWrite(koffiePin[7], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[7], HIGH);
        break;
      case 3:       
        Serial.println("Espresso wordt gemaakt");
        digitalWrite(koffiePin[9], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[9], HIGH);
        break;
      case 4:      
        Serial.println("Cafe au Lait wordt gemaakt");
        digitalWrite(koffiePin[3], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[3], HIGH);
        break;
      case 5:      
        Serial.println("Wiener Melange wordt gemaakt");
        digitalWrite(koffiePin[1], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[1], HIGH);
        break;
      case 6:     
        Serial.println("Dubbele Espresso wordt gemaakt");
        digitalWrite(koffiePin[6], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[6], HIGH);
        break;
      case 7:      
        Serial.println("Cafe Mocca wordt gemaakt");
        digitalWrite(koffiePin[2], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[2], HIGH);
        break;
      case 8:  
        Serial.println("Cafe Macchiato wordt gemaakt");
        digitalWrite(koffiePin[8], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[8], HIGH);
        break;
      case 9:  
        Serial.println("Esprechoc wordt gemaakt");
        digitalWrite(koffiePin[5], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[5], HIGH);
        break;
      case 10:   
        Serial.println("Hot Chocolate wordt gemaakt");
        digitalWrite(koffiePin[0], LOW);
        delay(delaytime);
        digitalWrite(koffiePin[0], HIGH);
        break;
      default: 
        Serial.println("Ongeldige input");
   }

  delay(5000);
  Serial.println("Coffee is ready");
  Serial.println("Test Completed");

}

int ReadOpticSensorDispense()
    {
      int value = 0;
      int sensor = analogRead(A1);
      delay(5);
      sensor = analogRead(A1);
      delay(5);

      if(sensor <= 750)
      {
        value = 1;                                      // Mug present
      }
      return value;
}

void testDispenser(){
  boolean cupPresent = ReadOpticSensorDispense();
  
  Servo servoDispense;
  servoDispense.attach(10);
  
  if(cupPresent == false){
    Serial.println("Start dispensing 135"); // print next position
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
      Serial.println("Dispense succeeded");
    }else{
      Serial.println("Failed to dispense");    
    }
  }
  else if(cupPresent == true) {
    Serial.println("Cup present");
  }

  Serial.println("Test Completed");
}

int ReadOpticSensorTake()
    {
      int value = 0;
      int sensor = analogRead(A2);
      delay(5);
      sensor = analogRead(A2);
      delay(5);

      if(sensor <= 750)
      {
        value = 1;                                      // Mug present
      }
      return value;
}

#define STEP 11
#define DIR 35

#define ENABLEPIN 31
#define RESETPIN 33

#define STEPDIVIDER 1/32    //Specifies amount of steps before a full step (1 , 1/2, 1/4, 1/8, 1/16, 1/32)
#define STEPS 200           //Steps of the Stepper motor for one full rotation

#define DEGREES (float)(STEPS/STEPDIVIDER)/360            //angle*Degrees -> Steps , steps/Degrees -> angle

#define ANGLE (float)270                                  // angle the motor will turn
#define ACCEL (float)5000                                 // acceleration used (steps/second^2)
#define MAXSPEED (float)1000                              // max speed the motor will run (steps/second)

#define MS_TURNTABLE_PIN 27                               // pin at which micro switch is attached
int MS_TURNTABLE = 1;                                     // variable for micro switch used for calibration
const float POS_REF = 3.66;

#define POS1 0
#define POS2 46.11
#define POS3 87.79
#define POS4 133.9
#define POS5 180
#define POS6 226.12
#define POS7 272.23
#define POS8 313.91
#define POS_DISP 270                                                      // position dispenser is at
#define POS_POUR 0                                                        // postition where coffee is poured
#define POS_TAKE 180                                                      // postition where coffee is taken
#define POS_READ 225                                                      // postition of NFC reader

float POS[] = {POS1,POS2,POS3,POS4,POS5,POS6,POS7,POS8};
int POSFILLED[] = {0,0,0,0,0,0,0,0};                                      // variable to store filled positions in

AccelStepper stepper(1, STEP, DIR);                     // initialize stepper

void calibrate(){
  stepper.moveTo((STEPS/STEPDIVIDER)*2);
  MS_TURNTABLE = digitalRead(MS_TURNTABLE_PIN); 
   
  while(stepper.distanceToGo() && MS_TURNTABLE == 1)     
     {
       stepper.run();
       MS_TURNTABLE = digitalRead(MS_TURNTABLE_PIN);      
     }
  stepper.stop();
  
      if (MS_TURNTABLE == 0){
        stepper.setCurrentPosition(POS_REF);                            // set angle the stepper is at
        MS_TURNTABLE = 1;
        Serial.println("Turntable at reference position");
      }
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

void MoveToDispenser(int location){
    float angle = POS_DISP - POS[(location-1)];
    TurnTable(angle);
}
void MoveToMachine(int location){
    float angle = POS_POUR - POS[(location-1)];
    TurnTable(angle);
}
void MoveToTake(int location){
    float angle = POS_TAKE - POS[(location-1)];
    TurnTable(angle);
}

void testTurningWheel(){
  AccelStepper stepper(1, STEP, DIR);

  pinMode(ENABLEPIN, OUTPUT);
  pinMode(RESETPIN, OUTPUT); 
  pinMode(MS_TURNTABLE_PIN, INPUT);

  stepper.setMaxSpeed(MAXSPEED);                        // set max speed of stepper
  stepper.setAcceleration(ACCEL);                       // set accelaration of stepper
  stepper.setCurrentPosition(0);                        // set current postition

  driverReset();
  driverOff();

  Serial.println("Calibrating");
  driverOn(); 
  calibrate();

  Serial.println("Please put a [cup] in the turntable");
  delay(1000);
  Serial.println("Enter the position of the [cup]:");

  //Wait for input
  while(!Serial.available()){}
  int pos = Serial.parseInt();
  if(pos > 8 || pos < 1){Serial.println("Unknown position, aborting test");return;} 
  
  Serial.println("Turning to dispenser");
  MoveToDispenser(pos);
  
  if(ReadOpticSensorDispense()){
    Serial.println("Turning to machine");
    MoveToMachine(pos);
  
      if(ReadOpticSensorMachine()){
        Serial.println("Turning to take out");
        MoveToTake(pos);

        if(ReadOpticSensorTake){
           Serial.println("Success"); return;    
        }else{
           Serial.println("Failed to detect cup at take out, aborting test"); return;       
        }
      }   
      else{
        Serial.println("Failed to detect cup at coffee machine, aborting test"); return;
      } 


  }else{
    Serial.println("Failed to detect cup at dispenser, aborting test"); return;
  }



}

#include <Servo.h>

void testDropCatcher(){
  Servo myservo;
  myservo.attach(12);  
  Serial.begin(9600);

  Serial.println("Opening dropCatcher");
  myservo.write(140);
  delay(1000);
  Serial.println("Opened");

  Serial.println("Closing dropCatcher");
  myservo.write(45);
  delay(1000);
  Serial.println("Closed");


  Serial.println("Test Completed");
}
