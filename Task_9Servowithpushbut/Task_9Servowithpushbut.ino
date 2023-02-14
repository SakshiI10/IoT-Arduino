//1 time pushed motor should go to 180 after that pushed once again should go to 0

#include <Servo.h>;

const int buttonPin = 3;
const int servoPin = 2;
Servo Myservo;
int counter = 0;
int buttonState; 

void setup()
{
Myservo.attach (servoPin);
pinMode(buttonPin, INPUT);
}

void loop()
{
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH)
{
counter++;
delay(250);
}

if(counter == 0)
Myservo.write (0); 

if(counter == 1) 
Myservo.write (180);

else
counter = 0;
}
