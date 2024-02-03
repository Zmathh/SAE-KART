#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include "..\1Librairies\SoftwareSerial\SoftwareSerial.h"

class GPS
{
public:
  GPS(uint8_t txPin, uint8_t rxPin);
  void begin();
  void readData();
  float latitude;
  float longitude;
  void flushBuffer();


private:
  SoftwareSerial gpsSerial;
  char buffer[64];
  int count;
  bool isGPGGA;
};

#endif