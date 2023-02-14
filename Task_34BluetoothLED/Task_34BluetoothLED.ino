//Blink a led
char val;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()){      //Get the number of bytes available for reading.
    val=Serial.read();          //Reads incoming serial data.
    Serial.println(val);
    if (val=='A'){
      digitalWrite(13,HIGH);}
      
    else if (val=='B'){
      digitalWrite(13,LOW);}}}
