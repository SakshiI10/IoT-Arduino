//PNP Proximity Sensor

int a ;

void setup() 
{
Serial.begin(9600);
pinMode(11,INPUT);
}

void loop() 
{
a=digitalRead(11);
if (a==HIGH){
  Serial.println("object detected");
}
else if (a==LOW)
{
    Serial.println(" no object detected");
}
}
