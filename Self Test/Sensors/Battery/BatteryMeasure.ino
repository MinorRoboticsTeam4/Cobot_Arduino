/* Written by Jaco Salentijn 567 258 825

  Uitleescode voor de accuspanning
  
 */
 
int refVcc = 12.0;      // referentiespanning
float corVal = 1.297;     // correctiefactor voor transformatie 12 naar 5 volt.
float Vcc;                // accuspanning
int Vcc_charge = 12.24; // oplaadspanning
int Vcc_stop = 11.96;   // kritieke spanning

void setup() {
  Serial.begin(9600);
}
 
void loop() {
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
  delay(1000);
}
