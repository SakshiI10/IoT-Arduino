#include <Arduino.h>

#define RXD2 16
#define TXD2 17

int dist;     // LiDAR actually measured distance value
int strength; // LiDAR signal strength
int check;    // check numerical value storage
int i;
int uart[9];             // store data measured by LiDAR
const int HEADER = 0x59; // data package frame header

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Started.");
  Serial2.begin(115200);
}

void loop()
{
  if (Serial2.available()) //check whether the serial port has data input
  {
    if (Serial2.read() == HEADER) // determine data package frame header 0x59
    {
      uart[0] = HEADER;
      if (Serial2.read() == HEADER) //determine data package frame header 0x59
      {
        uart[1] = HEADER;
        for (i = 2; i < 9; i++) // store data to array
        {
          uart[i] = Serial2.read();
        }
        check = uart[0] + uart[1] + uart[2] + uart[3] + uart[4] + uart[5] + uart[6] + uart[7];
        if (uart[8] == (check & 0xff)) // check the received data as per protocols
        {
          dist = uart[2] + uart[3] * 256;     // calculate distance value
          strength = uart[4] + uart[5] * 256; // calculate signal strength value
          Serial.print("dist = ");
          Serial.print(dist); // output LiDAR tests distance value
//          Serial.print('\t');
//          Serial.print("strength = ");
//          Serial.print(strength); // output signal strength value
//          Serial.print('\n');
        }
      }
    }
  }
}
