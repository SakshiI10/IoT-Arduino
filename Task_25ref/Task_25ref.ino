#define TRIGPIN 3
#define ECHOPIN 4
#define L298N_ENA 5
#define L298N_ENB 6
#define L298N_IN1 7
#define L298N_IN2 9
#define L298N_IN3 10
#define L298N_IN4 11

long duration;
long distance;

void setup()
{
  pinMode(L298N_ENA, OUTPUT);
  pinMode(L298N_ENB, OUTPUT);
  pinMode(L298N_IN1, OUTPUT);
  pinMode(L298N_IN2, OUTPUT);
  pinMode(L298N_IN3, OUTPUT);
  pinMode(L298N_IN4, OUTPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(TRIGPIN, LOW);           // Clears the TRIGPIN
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);          // Sets the TRIGPIN on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH);    // Reads the ECHOPIN, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;      // Calculating the distance

  if (distance > 10) {
    robotForward(150);
    Serial.print("Distance: ");
    Serial.println(distance);
  }
  else {
    robotTurnRight(150);
    Serial.print("Distance: ");
    Serial.println(distance);
  }
}

void robotStop()
{
  digitalWrite(L298N_ENA, LOW);
  digitalWrite(L298N_IN1, LOW);
  digitalWrite(L298N_IN2, LOW);

  digitalWrite(L298N_ENB, LOW);
  digitalWrite(L298N_IN3, LOW);
  digitalWrite(L298N_IN4, LOW);
}

void robotBreak()
{
  digitalWrite(L298N_ENA, HIGH);
  digitalWrite(L298N_IN1, HIGH);
  digitalWrite(L298N_IN2, HIGH);

  digitalWrite(L298N_ENB, HIGH);
  digitalWrite(L298N_IN3, HIGH);
  digitalWrite(L298N_IN4, HIGH);
}

void robotForward(int motorSpeed)
{
  analogWrite(L298N_ENA, motorSpeed);
  digitalWrite(L298N_IN1, LOW);
  digitalWrite(L298N_IN2, HIGH);

  analogWrite(L298N_ENB, motorSpeed);
  digitalWrite(L298N_IN3, HIGH);
  digitalWrite(L298N_IN4, LOW);
}

void robotReverse(int motorSpeed)
{
  analogWrite(L298N_ENA, motorSpeed);
  digitalWrite(L298N_IN1, HIGH);
  digitalWrite(L298N_IN2, LOW);

  analogWrite(L298N_ENB, motorSpeed);
  digitalWrite(L298N_IN3, LOW);
  digitalWrite(L298N_IN4, HIGH);
}

void robotTurnRight(int motorSpeed)
{
  analogWrite(L298N_ENA, motorSpeed);
  digitalWrite(L298N_IN1, HIGH);
  digitalWrite(L298N_IN2, LOW);

  analogWrite(L298N_ENB, motorSpeed);
  digitalWrite(L298N_IN3, HIGH);
  digitalWrite(L298N_IN4, LOW);
}

void robotTurnLeft(int motorSpeed)
{
  analogWrite(L298N_ENA, motorSpeed);
  digitalWrite(L298N_IN1, LOW);
  digitalWrite(L298N_IN2, HIGH);

  analogWrite(L298N_ENB, motorSpeed);
  digitalWrite(L298N_IN3, LOW);
  digitalWrite(L298N_IN4, HIGH);
}
