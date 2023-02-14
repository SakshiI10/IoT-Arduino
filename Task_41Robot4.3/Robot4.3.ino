#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(NOT_A_PIN, 11); 
SabertoothSimplified ST(SWSerial); 

void setup()
{
  SWSerial.begin(9600);
}

void loop(){
  Serial.print(millis()); 
if( millis()<=7000){
  ST.motor(1,-40);
  ST.motor(2,40);}
  
else if(millis()>=7001 && millis()<=9000){
  ST.motor(1,0);
  ST.motor(2,0);}
  
else if(millis()>=9001 && millis()<=10500){
  ST.motor(1,30);
  ST.motor(2,-30);}
else if(millis()>=10501 && millis()<=11500){
  ST.motor(1,0);
  ST.motor(2,0);}
    
else if(millis()>=11501 && millis()<=14000){
  ST.motor(1,-40);
  ST.motor(2,40);}
else if(millis()>=14001 && millis()<=15000){
  ST.motor(1,0);
  ST.motor(2,0);}
  
else if(millis()>=15001 && millis()<=18000){
  ST.motor(1,30);
  ST.motor(2,-30);}
else{
  ST.motor(1,0);
  ST.motor(2,0);}
}
