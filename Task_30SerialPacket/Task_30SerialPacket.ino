// Serial Packetized Mode of Sabertooth

#include <Sabertooth.h>
Sabertooth ST(128); // The Sabertooth is on address 128. We'll name its object ST.
                    
void setup()
{
  SabertoothTXPinSerial.begin(115200); // 9600 is the default baud rate for Sabertooth packet serial.
  ST.autobaud(); // Send the autobaud command to the Sabertooth controller(s).
                 
}
void loop()
{
  ST.motor(1, 127);
  ST.motor(2, -127);
  
}
