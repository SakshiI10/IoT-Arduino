#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(10, 11); 
SabertoothSimplified ST(SWSerial); 
int sensorValueW = 8;       
int sensorValueX = 7;        
int sensorValueY = 9;        
int sensorValueZ = 10;        
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
  outputValueW = map(sensorValueW, 986, 1972, -127, 0);
  ST.motor(1, outputValueW);
  Serial.print("output 1 = ");
  Serial.println(outputValueW);

  sensorValueX = pulseIn(7, HIGH);
  outputValueX = map(sensorValueX, 986, 1972, 0, 127);
  Serial.print("output 2 = ");
  Serial.println(outputValueX);
  ST.motor(2, outputValueX);}

//  sensorValueY = pulseIn(9, HIGH);
//  outputValueY = map(sensorValueY, 1171, 2071, 0, 127);
//  ST.motor(1, outputValueY);
//  Serial.print("output 3 = ");
//  Serial.println(outputValueY);
//
//  sensorValueZ = pulseIn(10, HIGH);
//  outputValueZ = map(sensorValueZ, 1171, 2071, -127, 0);
//  ST.motor(2, outputValueZ);
//  Serial.print("output 4 = ");
//  Serial.println(outputValueZ);}
