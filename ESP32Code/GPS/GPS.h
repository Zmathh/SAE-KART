// GPS_Reader.h

#ifndef GPS_READER_H
#define GPS_READER_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class GPSReader {
public:
  GPSReader(int rxPin, int txPin);
  void begin();
  void readGPS();
  void passThroughSerial();

private:
  SoftwareSerial softSerial;
  char buffer[64];
  int count;
  bool isGPGGA;
};

#endif
