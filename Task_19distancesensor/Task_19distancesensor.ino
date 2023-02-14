#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(NOT_A_PIN, 11); 
SabertoothSimplified ST(SWSerial); 
#include <ComponentObject.h>
#include <RangeSensor.h>
#include <SparkFun_VL53L1X.h>
#include <vl53l1x_class.h>
#include <vl53l1_error_codes.h>
#include <Wire.h>
#include "SparkFun_VL53L1X.h" 
#define SHUTDOWN_PIN 2
#define INTERRUPT_PIN 3
SFEVL53L1X distanceSensor;

void setup(void){
  Wire.begin();
  Serial.begin(115200);
  Serial.println("VL53L1X Qwiic Test");
  SWSerial.begin(9600);
  
  if (distanceSensor.begin() != 0) //Begin returns 0 on a good init
  {
    Serial.println("Sensor failed to begin. Please check wiring. Freezing...");
    while (1);}
  Serial.println("Sensor online!");}

void loop(void){
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  int distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();
  Serial.print("Distance(cm): ");
  Serial.print(distance);
  float distance2 = (distance * 0.034)/2;

if( distance<=7000){
  ST.motor(1,-40);
  ST.motor(2,40);}
  
else if(distance2>=7001 && distance2<=9000){
  ST.motor(1,0);
  ST.motor(2,0);}
  
else if(distance2>=9001 && distance2<=10500){
  ST.motor(1,30);
  ST.motor(2,-30);}

else if(distance2>=10501 && distance2<=11500){
  ST.motor(1,0);
  ST.motor(2,0);}
    
else if(distance2>=11501 && distance2<=14000){
  ST.motor(1,-40);
  ST.motor(2,40);}

else if(distance2>=14001 && distance2<=15000){
  ST.motor(1,0);
  ST.motor(2,0);}
  
else if(distance2>=15001 && distance2<=18000){
  ST.motor(1,30);
  ST.motor(2,-30);}

else{
  ST.motor(1,0);
  ST.motor(2,0);}}
