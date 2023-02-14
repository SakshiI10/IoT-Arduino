//To glow a led without using for loop

#include <Servo.h> 
Servo Servo1; 

void setup() 
{    
   Servo1.attach(3); 
}

void loop()
{     
   Servo1.write(0); 
   delay(1000); 
   
   Servo1.write(90); 
   delay(0); 
   
   Servo1.write(180); 
   delay(1000);
}
