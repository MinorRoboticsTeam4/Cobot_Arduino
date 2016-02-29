#include <Servo.h>

Servo servoDispenser; 
int servoDispenserPin = 10;

Servo servoDropCatcher; 
int servoDropCatcherPin = 12;

int servoChoice = -1;


void displayMenu(){
  Serial.println("Servo tester");
  Serial.println("Choose (1) for servo of dispenser");
  Serial.println("Choose (2) for servo of drop catcher");
}

void setup() {

  Serial.begin(9600);

  servoDispenser.attach(servoDispenserPin);  
  servoDropCatcher.attach(servoDropCatcherPin); 

  displayMenu();
}

void sweep(Servo servo,int sweep);
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

void loop() {

  if(Serial.available()){
    servoChoice = Serial.parseInt();
    Serial.print("Your choice is: ");
    Serial.println(servoChoice);
    switch(servoChoice){
      case 1: sweep(servoDispenser,90); displayMenu();break;
      case 2: sweep(servoDropCatcher,90); displayMenu();break;
      default: displayMenu(); break;  

    }
  }

}
