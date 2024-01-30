// GPS_Reader.h

#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class GPS_H {
public:
  GPS();

private:
  SoftwareSerial softSerial;
  char buffer[64];
  int count;
  bool isGPGGA;
};

#endif
