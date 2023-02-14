int temp = 0, counter = 0 ;
String encdir = "";

void setup() {
Serial.begin (9600);
pinMode (2, INPUT_PULLUP);
//Encoder

pinMode (3, INPUT_PULLUP); 
attachInterrupt(0, ai0 , RISING);
//attachInterrupt(1, ai1, RISING);}
}
void loop() {
Serial.println (counter);
}

void ai0() {
if (digitalRead(3) == HIGH) {
counter++; 
}
else if(digitalRead(2) == HIGH){
counter--;}
}
