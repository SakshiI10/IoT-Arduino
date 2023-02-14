#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(NOT_A_PIN, 5);
SabertoothSimplified ST(SWSerial);
const int s1 = 13;
int E1;
const int s2 = 12;
int E2;
const int s3 = 11;
int E3;
const int s4 = 10;
int E4;
const int s5 = 9;
int E5;
const int s6 = 8;
int E6;
const int s7 = 7;
int E7;
const int s8 = 6;
int E8;
void setup() {
  // put your setup code here, to run once:
  pinMode( s1, INPUT);
  pinMode( s2, INPUT);
  pinMode( s3, INPUT);
  pinMode( s4, INPUT);
  pinMode( s5, INPUT);
  pinMode( s6, INPUT);
  pinMode( s7, INPUT);
  pinMode( s8, INPUT);
  Serial.begin(9600);
  SWSerial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  E1 = digitalRead(s1);
  E2 = digitalRead(s2);
  E3 = digitalRead(s3);
  E4 = digitalRead(s4);
  E5 = digitalRead(s5);
  E6 = digitalRead(s6);
  E7 = digitalRead(s7);
  E8 = digitalRead(s8);
  if ( E4 == HIGH || E5 == HIGH ) {
    ST.motor(1, -90);
    ST.motor(2, 80);
  }
  if (E1 == HIGH || E2 == HIGH || E3 == HIGH) {
    ST.motor(1, 127);
    ST.motor(2, 90);
  }
  if ( E6 == HIGH || E7 == HIGH || E8 == HIGH) {
    ST.motor(1, -127);
    ST.motor(2, -90);
  }
  if (E1 == LOW && E2 == LOW && E3 == LOW && E4 == LOW && E5 == LOW && E6 == LOW && E7 == LOW && E8 == LOW) {
    ST.motor(1, -127);
    ST.motor(2, -127);
  }
}
