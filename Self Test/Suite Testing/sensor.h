
void testBattery(){
  int refVcc = 12.0;      // referentiespanning
  float corVal = 1.297;     // correctiefactor voor transformatie 12 naar 5 volt.
  float Vcc;                // accuspanning
  int Vcc_charge = 12.24; // oplaadspanning
  int Vcc_stop = 11.96;   // kritieke spanning

  float sensorValue = analogRead(A6);
  
  Serial.print("Analog value: ");
  Serial.println(sensorValue);

  Vcc = sensorValue*refVcc*corVal/1024;
  
  Serial.print("Battery voltage: ");
  Serial.print(Vcc);
  Serial.print("V +\r\n");

  if(Vcc > Vcc_charge){
    Serial.println("Battery OK");
  }
  else if(Vcc <= Vcc_charge && Vcc >= Vcc_stop){
    Serial.println("Battery Low");
  }
  else {
    Serial.println("Battery Critical");
  }
  Serial.println();

  Serial.println("Finished Test");
}

void testBumperswitch(){
  int buttonPin[] = {22, 23, 24, 25, 27, 29};     // the number of the pushbutton pins

  pinMode(buttonPin[0], INPUT);
  pinMode(buttonPin[1], INPUT);
  pinMode(buttonPin[2], INPUT);
  pinMode(buttonPin[3], INPUT);
  pinMode(buttonPin[4], INPUT);
  pinMode(buttonPin[5], INPUT);

  
  for(int i=0;i<6;++i){
    Serial.print("Please, push switch: ");Serial.print(i+1);Serial.print("\r\n");

    int startTime = millis();
    int elapsedTime = 0;
    boolean detected = false;
    while(elapsedTime < 5000){
      if(digitalRead(buttonPin[i]) == HIGH){
        Serial.println("Switch detected");
        detected = true;
        break;
      }
       elapsedTime = millis() - startTime;    
    }

    if(detected == false){
      Serial.println("Failed to detect switch");    
    }

  }

  Serial.println("Finished Test");
 
}

void testLight(){

int ADC_stabilize = 5;
int lightThreshold = 750;
boolean somethingAbove[4] = {false,false,false,false};

 for(int i=0;i<4;++i){
    Serial.println("Make sure nothing is above light sensors: ");

    int startTime = millis();
    int elapsedTime = 0;

    while(elapsedTime < 10000){
      if(analogRead(A0) <= lightThreshold){
        Serial.println("Please remove object from sensor 1");
        somethingAbove[0] = true;
      }
      else if(analogRead(A0) > lightThreshold){
        somethingAbove[0] = false;
      }
      else if(analogRead(A1) <= lightThreshold){
        Serial.println("Please remove object from sensor 2");
        somethingAbove[1] = true;
      }
      else if(analogRead(A1) > lightThreshold){
        somethingAbove[1] = false;
      }
      else if(analogRead(A2) <= lightThreshold){
        Serial.println("Please remove object from sensor 3");
        somethingAbove[2] = true;
      }
      else if(analogRead(A2) > lightThreshold){
        somethingAbove[2] = false;
      }
      else if(analogRead(A3) <= lightThreshold){
        Serial.println("Please remove object from sensor 4");
        somethingAbove[3] = true;
      }
      else if(analogRead(A3) > lightThreshold){
        somethingAbove[3] = false;
      }
       elapsedTime = millis() - startTime;    
    }
    if(!somethingAbove[0] && !somethingAbove[1] && !somethingAbove[2] && !somethingAbove[3]){break;}
  }

  for(int i=0;i<4;++i){
    if(somethingAbove[i]){
      Serial.print("Light sensor: ");Serial.print(i);Serial.print(" is not working \r\n");  
    }
  }

  for(int i=0;i<4;++i){
    Serial.print("Please, cover light sensor: ");Serial.print(i+1);Serial.print("\r\n");

    int startTime = millis();
    int elapsedTime = 0;
    boolean detected = false;
    while(elapsedTime < 5000){
      if(i == 0 && analogRead(A0) <= lightThreshold){
        Serial.println("Light sensor working");
        detected = true;
        break;
      }
      else if(i == 1 && analogRead(A1) <= lightThreshold){
        Serial.println("Light sensor working");
        detected = true;
        break;
      }
      else if(i == 2 &&analogRead(A2) <= lightThreshold){
        Serial.println("Light sensor working");
        detected = true;
        break;
      }
      else if(i == 3 && analogRead(A3) <= lightThreshold){
        Serial.println("Light sensor working");
        detected = true;
        break;
      }
       elapsedTime = millis() - startTime;    
    }

    if(detected == false){
      Serial.println("Failed to detect change in light");    
    }

  }

  Serial.println("Finished Test");
}



void testUltrasoon(){
  int trigger_pins[8] = {26,28,30,32,34,36,38,40}; 
  int echo_pins[8] = {2,3,4,5,6,7,8,9}; 

  for(int i=0;i<8;++i){
    pinMode(trigger_pins[i], OUTPUT);
    pinMode(echo_pins[i], INPUT);
  }



for(int i=0;i<8;++i){
  Serial.print("Please, put something in front of ultrasoon: ");Serial.print(i);Serial.print("\r\n");
  int startTime = millis();
  int elapsedTime = 0;
  boolean works = false;
   while(elapsedTime < 5000){
     digitalWrite(trigger_pins[i], LOW); 
     delayMicroseconds(2); 

     digitalWrite(trigger_pins[i], HIGH);
     delayMicroseconds(10); 
     
     digitalWrite(trigger_pins[i], LOW);
     float duration = pulseIn(echo_pins[i], HIGH);
     
     float distance = duration/58.2;
     
     if (distance >= 200 || distance <= 0){
       Serial.println("-1");
     }else{
        Serial.println("Ultrasoon is working");
        works = true;
     }

     delay(50);
  }
  if(!works){
    Serial.println("Test failed, (time run out or sensor is broken)");
  }
  

}

  Serial.println("Finished Test");
}
