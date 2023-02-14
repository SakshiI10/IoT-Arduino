int pwm = 11;
int in1 = 13;
int in2 =12;


void setup() 
{
  pinMode(pwm, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}


void loop() 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  analogWrite(pwm, 255);
  delay(60000);
  
  digitalWrite(in1, HIGH);       //For brake
  digitalWrite(in2, HIGH); 
  delay(2000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(pwm, 255);
  delay(60000);
  
  digitalWrite(in1, HIGH);       //For brake
  digitalWrite(in2, HIGH); 
  delay(2000);
}
