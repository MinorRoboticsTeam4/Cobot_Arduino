#define pinEnable 13 // Enable (DIGITAL)
#define pinStep    9 // Step (PWM)
#define pinDir     8 // Direction (DIGITAL)

void setup(){
  Serial.begin(9600);
  Serial.println("Test DRV8825");
  
  pinMode( pinEnable, OUTPUT );
  pinMode( pinDir   , OUTPUT );
  pinMode( pinStep  , OUTPUT );
}

void loop(){
  int i = 0;
  
  digitalWrite( pinDir   , HIGH);
  digitalWrite( pinStep  , LOW);
  
  // 200 Steps
  for( i=0; i<200; i++){
    Serial.println( i );
    digitalWrite( pinStep, HIGH );
    delay( 10 );
    digitalWrite( pinStep, LOW );
    delay( 10 );
  } 
  
  // Change the direction
  digitalWrite( pinDir   , LOW);
  
  // 200 steps, other direction
  for( i=0; i<200; i++){
    Serial.println( i );
    digitalWrite( pinStep, HIGH );
    delay( 1 );
    digitalWrite( pinStep, LOW );
    delay( 1 );
  } 

  // Axis is blocked
  Serial.println("As is geblokkeerd, 5 seconden wachten");
  delay( 5000 );
  
  // Motor is blocked
  Serial.println("Deblokeer de motor");
  digitalWrite( pinEnable, HIGH );
  
  // Reset
  Serial.println("Reset motor");
  while( true );
}
