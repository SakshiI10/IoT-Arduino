bv #include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(10, 11); 
SabertoothSimplified ST(SWSerial); 

int pulse = 7;
int Value =0;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  SWSerial.begin(9600); }

void loop() {  
  pulse = pulseIn(7, HIGH);
  Value = map(pulse, 1171, 2065,-40, 40);
  ST.motor(1, Value);
  ST.motor(2, -Value);
 Serial.println(-Value);}
