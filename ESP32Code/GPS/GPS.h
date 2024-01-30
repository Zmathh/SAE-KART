// GPS_Reader.h

#ifndef GPS_READER_H
#define GPS_READER_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class GPSReader {
public:
  GPS();

private:
  SoftwareSerial softSerial;
  char buffer[64];
  int count;
  bool isGPGGA;
};

#endif
