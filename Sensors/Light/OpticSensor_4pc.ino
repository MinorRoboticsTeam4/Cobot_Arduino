int sensor_0, sensor_1, sensor_2, sensor_3; //optical sensor values
String tmp;
int ADC_stabilize = 5;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  //take a snapshot
  sensor_0 = analogRead(A0);
  delay(ADC_stabilize); //stabilize
  sensor_0 = analogRead(A0);
  delay(ADC_stabilize);

  sensor_1 = analogRead(A1);
  delay(ADC_stabilize);
  sensor_1 = analogRead(A1);
  delay(ADC_stabilize);

  sensor_2 = analogRead(A2);
  delay(ADC_stabilize);
  sensor_2 = analogRead(A2);
  delay(ADC_stabilize);

  sensor_3 = analogRead(A3);
  delay(ADC_stabilize);
  sensor_3 = analogRead(A3);
  delay(ADC_stabilize);

  tmp = "0=" + String(sensor_0) + " 1=" + String(sensor_1) + " 2=" + String(sensor_2) + " 3=" + String(sensor_3); 

  // send the value of analog inputs:
  Serial.println(tmp);

  // wait a bit for next reading
  delay(1000); //1000=1 sec
}
