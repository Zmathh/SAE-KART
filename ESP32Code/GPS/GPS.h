#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include "../1Librairies/SoftwareSerial/SoftwareSerial.h"

class GPS_H {
public:
  GPS_H(); 
private:
  char buffer[64];
  int count;
  bool isGPGGA;
};

#endif