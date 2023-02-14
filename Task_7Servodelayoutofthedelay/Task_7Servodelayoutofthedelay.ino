/*Using Loop out of the loop*/

#include <Servo.h>

Servo myservo;  
unsigned long Time ;
int pos = 0;
unsigned int Time1;
unsigned int Time2;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(180);
}

void loop() 
{
  Time1=millis();
  for (pos = 0; pos <= 179; pos += 1) 
  { 
    myservo.write(pos); 
    delay(12);
  }
  delay(2);
 
  for (pos = 180; pos >= 0; pos -= 1) 
  {
    myservo.write(pos);              
    delay(12);
  }
  delay(2);
  
  Time2=millis(); 
  Serial.println(Time2-Time1);
}
