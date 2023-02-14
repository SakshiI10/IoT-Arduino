int ir_pin = 8;
int counter = 0;
int hitObject = false;

void setup() {
  Serial.begin(9600);
  pinMode(ir_pin,INPUT);
}

void loop() {

   int val = digitalRead(ir_pin);

   if( (val == 0) && (hitObject == false) ){
        counter++;
        hitObject = true;
        Serial.print("Counter = ");
        Serial.println( counter);
   }else if( (val ==1) && (hitObject == true) ) {
        hitObject = false;
   }}