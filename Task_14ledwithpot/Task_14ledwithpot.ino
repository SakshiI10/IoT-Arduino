//To control intensity of led using potentiometer and display the values on the serial monitor

int ledpin= 13;
int readValue;
int ledstrength;

void setup() 
{
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
}

void loop() 
{
readValue= analogRead(A0);
Serial.print(     "readValue");
Serial.print(readValue);
delay(200);

ledstrength= map(readValue,0,1024,0,255);
analogWrite(13, ledstrength);
Serial.print(     "ledstrength");
Serial.println(ledstrength);
delay(200);
}
