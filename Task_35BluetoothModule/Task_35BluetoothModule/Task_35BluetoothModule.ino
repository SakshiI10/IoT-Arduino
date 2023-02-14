#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(NOT_A_PIN, 11);
SabertoothSimplified ST(SWSerial); 
char val;

void setup() {
  SWSerial.begin(9600);
  Serial.begin(9600);
  pinMode(13, OUTPUT);}

void loop() {
  if (Serial.available()){      //Get the number of bytes available for reading.
    val=Serial.read();          //Reads incoming serial data.
    Serial.println(val);
    if (val=='A'){
      ST.motor(1, 20);
      ST.motor(2, -20);}
      
    else if (val=='B'){
      ST.motor(1, -50);
      ST.motor(2, 50);}
      
    else if (val=='C'){
    ST.motor(1, 0);
    ST.motor(2, 0);}}}
