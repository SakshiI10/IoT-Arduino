//NPN Proximity Sensor

int a ;

void setup() 
{
Serial.begin(9600);
pinMode(11,INPUT);
}

void loop() 
{
a=digitalRead(11);
if (a==LOW){
  Serial.println("object detected");
}
else if (a==HIGH)
{
    Serial.println(" no object detected");
}
}
