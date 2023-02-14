#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(10, 11); 
SabertoothSimplified ST(SWSerial); 
int sensorValueW = 0;       
int sensorValueX = 0;        
int sensorValueY = 0;        
int sensorValueZ = 0;        
int outputValueW = 0;       
int outputValueX = 0;       
int outputValueY = 0;       
int outputValueZ = 0;       

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  SWSerial.begin(9600); }

void loop() {  
  sensorValueW = pulseIn(8, HIGH);
  outputValueW = map(sensorValueW, 1171, 2065, 50, 70);
  Serial.print("output = ");
  Serial.println(outputValueW);
  ST.motor(1, outputValueW);

  sensorValueX = pulseIn(9, HIGH);
  outputValueX = map(sensorValueX, 1171, 2065, 40, 70);
  Serial.print("output = ");
  Serial.println(outputValueX);
  ST.motor(2, outputValueX);

  sensorValueY = pulseIn(10, HIGH);
  outputValueY = map(sensorValueY, 1171, 2065, -30, -50);
  Serial.print("output = ");
  Serial.println(outputValueY);
  ST.motor(1, outputValueY);

  sensorValueZ = pulseIn(11, HIGH);
  outputValueZ = map(sensorValueZ, 1171, 2065, -20, 40);
  Serial.print("output = ");
  Serial.println(outputValueZ);
  ST.motor(2, outputValueZ);}
