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
int isChoiceMade; 

void setup() {
  Serial.begin(9600);

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

  isChoiceMade = 1;

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

void showMenu(){
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

void loop() {
  while(!ReadOpticSensorMachine()){
      Serial.println("Plaats een beker/mok onder de koffiemachine");
      delay(1000);
  }

  if(isChoiceMade == 1){
    showMenu();
    isChoiceMade = 0;
  }


  while(!Serial.available()){}
    value = Serial.parseInt();
    Serial.print("U heeft gekozen voor keuze: ");
    Serial.println(value);
    if(value != 0){
      isChoiceMade = 1;

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
        Serial.println("Ongeldige input, kies voor een getal tussen 1 en 10");
   }
      
    //Tijd voor koffie zetten
    delay(5000);
    Serial.println("Koffie is klaar");

  }

 
    value = 0;

    
}

