#include <NewPing.h>
 
#define SONAR_NUM     8 // Number or sensors.
#define MAX_DISTANCE 200 // Max distance in cm.
#define PING_INTERVAL 50 // Milliseconds between pings.
 
unsigned long pingTimer[SONAR_NUM]; // When each pings.
unsigned int cm[SONAR_NUM]; // Store ping distances.
uint8_t currentSensor = 0; // Which sensor is active.
unsigned int cmp[SONAR_NUM]; // Previous distance.
 
NewPing sonar[SONAR_NUM] = { // Sensor object array.
  NewPing(26, 2, MAX_DISTANCE),
  NewPing(28, 3, MAX_DISTANCE),
  NewPing(30, 4, MAX_DISTANCE),
  NewPing(32, 5, MAX_DISTANCE),
  NewPing(34, 6, MAX_DISTANCE),
  NewPing(36, 7, MAX_DISTANCE),
  NewPing(38, 8, MAX_DISTANCE),
  NewPing(40, 9, MAX_DISTANCE)
};
 
void setup() {
  Serial.begin(115200);
  pingTimer[0] = millis() + 100; // First ping start in 100 ms.
  for (uint8_t i = 1; i < SONAR_NUM; i++)
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}
 
void loop() {
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    if (millis() >= pingTimer[i]) {
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;
      if (i == 0 && currentSensor == SONAR_NUM - 1)
        oneSensorCycle(); // Do something with results.
      sonar[currentSensor].timer_stop();
      currentSensor = i;
      cm[currentSensor] = 404; // error
      sonar[currentSensor].ping_timer(echoCheck);
    }
  }
  // The rest of your code would go here.
}
 
void echoCheck() { // If ping echo, set distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}
 
void oneSensorCycle() { // Do something with the results.
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    if(cm[i] == 404)
    {
      cm[i] = cmp[i];
      Serial.print(cm[i]);
      Serial.print("*");
    }
    else
    {
      Serial.print(cm[i]);
    }
    Serial.print("cm ");
    cmp[i] = cm[i];
  }
  Serial.println();
}
