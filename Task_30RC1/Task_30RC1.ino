#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(10, 11); 
SabertoothSimplified ST(SWSerial); // Use SWSerial as the serial port.
int re_pulse=8;
int Value=0;

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  }

void loop() {   
re_pulse  = pulseIn(8, HIGH);
//  if(re_pulse >1100) 
  { 
    Serial.println(re_pulse);
  }
}
