//To glow a led when pressed 3 times until pressed 3 times again

const int  buttonPin = 7;    
const int ledPin = 8;       
int counter = 1;   
int buttonState = 0;         
int lastButtonState = 0;     

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) 
  {
    if (buttonState == HIGH) 
    {
      counter++;
      Serial.println(counter);
    }
    delay(50);
  }
  lastButtonState = buttonState;
  if (counter >= 6) 
  {
    digitalWrite(ledPin, HIGH);
    counter = 0;
  }
  else if (counter == 3)
  {
    digitalWrite(ledPin, LOW);
  }
}
