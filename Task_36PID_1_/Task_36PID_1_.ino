#include <SoftwareSerial.h>
#include <SabertoothSimplified.h>
SoftwareSerial SWSerial(NOT_A_PIN, 11); // RX on no pin (unused), TX on pin 11 (to S1).
SabertoothSimplified ST(SWSerial); // Use SWSerial as the serial port.
float Setpoint=0;
#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
unsigned long timer = 0;
float timeStep = 0.1;
float yaw = 0;

void setup() 
{
  Serial.begin(9600);
  SWSerial.begin(9600);
  // Initialize MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)){
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);}
  
  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  //  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);}

void loop()
{ float kp;
  timer = millis();
  // Read normalized values
  Vector norm = mpu.readNormalizeGyro();
  yaw = yaw + norm.ZAxis * timeStep;
   Serial.print(" Yaw = ");
   Serial.println(yaw);
kp = (yaw+Setpoint)*8;
ST.motor(1,-(50-kp));
ST.motor(2,-(50+kp));}
