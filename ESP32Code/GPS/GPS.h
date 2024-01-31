#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include "../1Librairies/SoftwareSerial/SoftwareSerial.h"

class GPS
{
public:
  GPS(uint8_t rxPin, uint8_t txPin);
  void begin(uint32_t baudRate);
  void readData();

private:
  SoftwareSerial gpsSerial;
  char buffer[64];
  int count;
  bool isGPGGA;
};

#endif