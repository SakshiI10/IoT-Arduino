//Calculating distance using ultrasonic sensor

const int trigPin=10;
const int echoPin=11;
long duration;
long distance;

void setup() 
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration=pulseIn(echoPin, HIGH);
  distance=(duration*0.034)/2;

  Serial.print("Distance: ");
  Serial.println(distance);
}
