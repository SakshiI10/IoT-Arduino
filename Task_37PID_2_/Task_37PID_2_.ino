#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(NOT_A_PIN, 11); // RX on no pin (unused), TX on pin 11 (to S1).
SabertoothSimplified ST(SWSerial); // Use SWSerial as the serial port.
float Setpoint=0;
#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;

// Timers
unsigned long timer = 0;
float timeStep = 0.01;
float kp;

// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;

void setup() 
{
  Serial.begin(115200);
  SWSerial.begin(9600);
  // Initialize MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  mpu.calibrateGyro(1);
  mpu.setThreshold(1);
}

void loop()
{ 
 Vector norm = mpu.readNormalizeGyro();
 yaw = yaw + norm.ZAxis * timeStep;
 Serial.print(" Yaw = ");
 Serial.println(yaw);
 
 kp = (yaw+Setpoint)*8;
 if(yaw==0){
  ST.motor(1,-40 );
  ST.motor(2,40);
  Serial.println("STRAIGHT");} 
  
 else if(yaw>0){
  ST.motor(1,-(40+kp));  
  ST.motor(2,(40+kp));
  Serial.println("RIGHT");}
  
 else if( yaw<0){
  ST.motor(1,-(40+kp));
  ST.motor(2,(40+kp));
  Serial.println("LEFT");
}}
