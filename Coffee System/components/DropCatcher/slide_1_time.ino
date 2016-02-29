// Written by Pieter van der Gaag
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(12);  
  Serial.begin(9600);
}

void loop() {
  Serial.println("Start 40");          // print next position
  myservo.write(45);                   // sets the servo position to start position
  delay(3000);                         // waits for the servo to get there
  Serial.println("140");               // print next position
  myservo.write(140);                  // sets the servo position to end position            
  delay(4000);                         // waits for the servo to get there
  Serial.println("45");                // print next position
  myservo.write(45);                   // sets the servo position to start position
  delay(15);                           // waits for the servo to get there
  delay(3000);                         // delay before while loop starts
  while(1){
    myservo.write(45);                 // write servo to mid-postition
    Serial.println("While");
    delay(1000);
    };
}

