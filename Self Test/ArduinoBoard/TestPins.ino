#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7
#define pin8 8
#define pin9 9
#define pin10 10
#define pin11 11
#define pin12 12
#define pin13 13
#define pin14 14
#define pin15 15
#define pin16 16
#define pin17 17
#define pin18 18
#define pin19 19
#define pin20 20
#define pin21 21
#define pin22 22
#define pin23 23
#define pin24 24
#define pin25 25
#define pin26 26
#define pin27 27
#define pin28 28
#define pin29 29
#define pin30 30
#define pin31 31
#define pin32 32
#define pin33 33
#define pin34 34
#define pin35 35
#define pin36 36
#define pin37 37
#define pin38 38
#define pin39 39
#define pin40 40
#define pin41 41
#define pin42 42
#define pin43 43
#define pin44 44
#define pin45 45
#define pin46 46
#define pin47 47
#define pin48 48
#define pin49 49
#define pin50 50
#define pin51 51
#define pin52 52
#define pin53 53

int oldval;

void setup() {
  Serial.begin(9600);
  
  pinMode( pin1, OUTPUT );
  pinMode( pin2, OUTPUT );
  pinMode( pin3, OUTPUT );
  pinMode( pin4, OUTPUT );
  pinMode( pin5, OUTPUT );
  pinMode( pin6, OUTPUT );
  pinMode( pin7, OUTPUT );
  pinMode( pin8, OUTPUT );
  pinMode( pin9, OUTPUT );
  pinMode( pin10, OUTPUT );
  pinMode( pin11, OUTPUT );
  pinMode( pin12, OUTPUT );
  pinMode( pin13, OUTPUT );
  pinMode( pin14, OUTPUT );
  pinMode( pin15, OUTPUT );
  pinMode( pin16, OUTPUT );
  pinMode( pin17, OUTPUT );
  pinMode( pin18, OUTPUT );
  pinMode( pin19, OUTPUT );
  pinMode( pin20, OUTPUT );
  pinMode( pin21, OUTPUT );
  pinMode( pin22, OUTPUT );
  pinMode( pin23, OUTPUT );
  pinMode( pin24, OUTPUT );
  pinMode( pin25, OUTPUT );
  pinMode( pin26, OUTPUT );
  pinMode( pin27, OUTPUT );
  pinMode( pin28, OUTPUT );
  pinMode( pin29, OUTPUT );
  pinMode( pin30, OUTPUT );
  pinMode( pin31, OUTPUT );
  pinMode( pin32, OUTPUT );
  pinMode( pin33, OUTPUT );
  pinMode( pin34, OUTPUT );
  pinMode( pin35, OUTPUT );
  pinMode( pin36, OUTPUT );
  pinMode( pin37, OUTPUT );
  pinMode( pin38, OUTPUT );
  pinMode( pin39, OUTPUT );
  pinMode( pin40, OUTPUT );
  pinMode( pin41, OUTPUT );
  pinMode( pin42, OUTPUT );
  pinMode( pin43, OUTPUT );
  pinMode( pin44, OUTPUT );
  pinMode( pin45, OUTPUT );
  pinMode( pin46, OUTPUT );
  pinMode( pin47, OUTPUT );
  pinMode( pin48, OUTPUT );
  pinMode( pin49, OUTPUT );
  pinMode( pin50, OUTPUT );
  pinMode( pin51, OUTPUT );
  pinMode( pin52, OUTPUT );
  pinMode( pin53, OUTPUT );

  digitalWrite( pin1, HIGH );
  digitalWrite( pin2, LOW );
  digitalWrite( pin3, LOW );
  digitalWrite( pin4, LOW );
  digitalWrite( pin5, LOW );
  digitalWrite( pin6, LOW );
  digitalWrite( pin7, LOW );
  digitalWrite( pin8, LOW );
  digitalWrite( pin9, LOW );
  digitalWrite( pin10, LOW );
  digitalWrite( pin11, LOW );
  digitalWrite( pin12, LOW );
  digitalWrite( pin13, LOW );
  digitalWrite( pin14, LOW );
  digitalWrite( pin15, LOW );
  digitalWrite( pin16, LOW );
  digitalWrite( pin17, LOW );
  digitalWrite( pin18, LOW );
  digitalWrite( pin19, LOW );
  digitalWrite( pin20, LOW );
  digitalWrite( pin21, LOW );
  digitalWrite( pin22, LOW );
  digitalWrite( pin23, LOW );
  digitalWrite( pin24, LOW );
  digitalWrite( pin25, LOW );
  digitalWrite( pin26, LOW );
  digitalWrite( pin27, LOW );
  digitalWrite( pin28, LOW );
  digitalWrite( pin29, LOW );
  digitalWrite( pin30, LOW );
  digitalWrite( pin31, LOW );
  digitalWrite( pin32, LOW );
  digitalWrite( pin33, LOW );
  digitalWrite( pin34, LOW );
  digitalWrite( pin35, LOW );
  digitalWrite( pin36, LOW );
  digitalWrite( pin37, LOW );
  digitalWrite( pin38, LOW );
  digitalWrite( pin39, LOW );
  digitalWrite( pin40, LOW );
  digitalWrite( pin41, LOW );
  digitalWrite( pin42, LOW );
  digitalWrite( pin43, LOW );
  digitalWrite( pin44, LOW );
  digitalWrite( pin45, LOW );
  digitalWrite( pin46, LOW );
  digitalWrite( pin47, LOW );
  digitalWrite( pin48, LOW );
  digitalWrite( pin49, LOW );
  digitalWrite( pin50, LOW );
  digitalWrite( pin51, LOW );
  digitalWrite( pin52, LOW );
  digitalWrite( pin53, LOW );
  
  oldval = 0;

  Serial.println("Pin 0 is currently HIGH");
}

void loop() {

  while(Serial.available()){
    Serial.print("Set only this pin too HIGH: ");
    int val = Serial.parseInt();
    Serial.print(val);
    Serial.println();
    if(val != oldval){
      digitalWrite(val   , HIGH);
      digitalWrite(oldval, LOW);
    }
    oldval = val;
  }
}
