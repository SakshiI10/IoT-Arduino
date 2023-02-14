#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(10, 11); 
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
int flag=0;
SFEVL53L1X distanceSensor;

void setup(void)
{ SWSerial.begin(9600);
  Wire.begin();
  Serial.begin(115200);
  Serial.println("VL53L1X Quick  Test");
  if (distanceSensor.begin() != 0)  {
    Serial.println("Sensor failed to begin");
    while (1);}
    Serial.println("Sensor online!");}

void loop(void){
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady()){
    delay(1);}
  int distance = distanceSensor.getDistance(); 
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();
  Serial.print("Distance(mm): ");
  Serial.println(distance);
  float distanceInches = (distance * 0.034)/2;

if (flag ==0){  
if (distance<=700 && distance >=240){
  Serial.print(distance);
  Serial.println("   AAAAAAAAAA");
  ST.motor(1, -40);
  ST.motor(2, 40);}}
  
if ( distance == 700 ){
flag = 1;} 

if (flag ==1){
if (distance <= 700 && distance >=500){
  Serial.print(distance);
  Serial.println("   BBBBBBBBBB");
  ST.motor(1, 30);
  ST.motor(2, -30);}} 
   
if (distance == 500 ){
flag = 2;} 

if (flag == 2){
if (distance <= 680 && distance >=500){
  Serial.print(distance);
  Serial.println("   CCCCCCCCCC");
  ST.motor(1, -40);
  ST.motor(2, 40);}} 

if (distance == 680){
flag = 3;}

if (flag == 3){
if (distance <= 680 && distance >=240){
  Serial.print(distance);
  Serial.println("   DDDDDDDDDD");
  ST.motor(1, -30);
  ST.motor(2, 30);}} 

if (distance == 240){
flag = 4;}

if (flag == 4){
if (distance == 240){
  Serial.print(distance);
  Serial.println("   EEEEEEEEEE");
  ST.motor(1, 0);
  ST.motor(2, 0);}}
  return;}
