//OPerating Servo Motor to rotate from 0 to 180 from 10 cm to 20 cm and vice versa

#include<Servo.h>

int trigPin = 3;
int echoPin = 2;
Servo servo1;
Servo servo2;
int angle = 0;
long duration, distance;

void setup() 
{
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  servo1.attach(4);
  servo1.write(angle);
  servo2.attach(12);
  servo2.write(angle);
}

void loop() 
{
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration*0.034)/2;
  Serial.println(distance);

if (distance < 10) {
servo1.write(90);
servo2.write(0);
}
else {
servo1.write(0);
servo2.write(90);
}
}
