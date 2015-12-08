int buttonPin[] = {22, 23, 24, 25, 27, 29};     // the number of the pushbutton pins
int buttonState[6];                             // variable for reading the pushbuttons status

void setup() {
  // initialize the pushbutton pins as an input:
  pinMode(buttonPin[1], INPUT);
  pinMode(buttonPin[2], INPUT);
  pinMode(buttonPin[3], INPUT);
  pinMode(buttonPin[4], INPUT);
  pinMode(buttonPin[5], INPUT);
  pinMode(buttonPin[6], INPUT);
}

void loop() {
  int i = 0;
  // read the state of the pushbutton value:
  for(i=0; i<6; i++){
  buttonState[i] = digitalRead(buttonPin[i]);
  }
  
  // check if the pushbutton in body is pressed.
  for(i=0; i<4; i++){
    if (buttonState[i] == HIGH) {
      // Stop the robot!!
    }
  }
  // check if the pushbutton in turning table is pressed.
  for(i=5; i<6; i++){
    if (buttonState[i] == HIGH) {
      // I don't know.......
    }
  }
}
