//Blink a led

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  digitalWrite(LED_BUILTIN,HIGH);  //LED WILL GLOW
  delay(1000);                     //1000 MILLISECONDS OR 1 SEC TO DO NOTHING
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}
