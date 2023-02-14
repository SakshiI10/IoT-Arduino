/*Robot_1: Locomotion using an ultrasonic sensor and JGM with 2 cytron Motor driver*/

#include "CytronMotorDriver.h"
#define trigpin 8
#define echopin 9
// Configure the motor driver.
CytronMD motor1(PWM_DIR, 3, 4);   
CytronMD motor2(PWM_DIR, 6, 7); 
long duration;
long distance;

void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,INPUT);
}

// The loop routine runs over and over again forever.
void loop() {
  digitalWrite(trigpin, LOW);           // Clears the TRIGPIN
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);          // Sets the TRIGPIN on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);    // Reads the ECHOPIN, returns the sound wave travel time in microseconds
  distance = (duration * 0.034)/ 2;      // Calculating the distance

  if (distance > 10) {
    Serial.print("Distance: ");
    Serial.println(distance);
    motor1.setSpeed(128);
    motor2.setSpeed(-128);
  }
  else {
    Serial.print("Distance: ");
    Serial.println(distance);
    motor1.setSpeed(0);
    motor2.setSpeed(0);
  } 
}
