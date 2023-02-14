/*Robot_2: Locomotion using 2 ultrasonic sensor and JGM with 2 cytron Motor driver*/

#include "CytronMotorDriver.h"
#define trig1 8
#define echo1 9
#define trig2 11
#define echo2 12
CytronMD motor1(PWM_DIR, 3, 4);   
CytronMD motor2(PWM_DIR, 6, 7); 
long duration1;
long distance1;
long duration2;
long distance2;


void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,INPUT);
}

void loop() {
  digitalWrite(trig1, LOW); 
  delayMicroseconds(1);
  digitalWrite(trig1, HIGH); 
  delayMicroseconds(8);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH); 

  digitalWrite(trig2, LOW); 
  delayMicroseconds(1);
  digitalWrite(trig2, HIGH); 
  delayMicroseconds(8);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH); 

  distance1 = (duration1 * 0.034)/ 2;      
  distance2 = (duration2 * 0.034)/ 2;      
  
if (distance1 < 15){
    Serial.print("Distance1: ");
    Serial.println(distance1);
    Serial.print("Distance2: ");
    Serial.println(distance2);
    motor1.setSpeed(150);
    motor2.setSpeed(185);
  } 

else if (distance2 < 15){
    Serial.print("Distance1: ");
    Serial.println(distance1);
    Serial.print("Distance2: ");
    Serial.println(distance2);
    motor1.setSpeed(150);
    motor2.setSpeed(185);
  } 
else {
    Serial.print("Distance1: ");
    Serial.println(distance1);
    Serial.print("Distance2: ");
    Serial.println(distance2);
    motor1.setSpeed(148);
    motor2.setSpeed(-148);}
}
