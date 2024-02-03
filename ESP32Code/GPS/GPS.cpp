#include "GPS.h"

GPS::GPS(uint8_t txPin, uint8_t rxPin) : gpsSerial(txPin, rxPin) {
  buffer[64];
  count = 0;
  isGPGGA = false;
}

void GPS::begin() {
  gpsSerial.begin(9600);
}

void GPS::flushBuffer() {
  if (latitude != 0.0 || longitude != 0.0){
      memset(buffer, 0, sizeof(buffer));
  }        
}

void GPS::readData() {
  if (gpsSerial.available()) {
    char incomingChar = gpsSerial.read();

    if (incomingChar == '$') {
      count = 0;
      isGPGGA = false;
    }

    buffer[count] = incomingChar;
    count++;

    if (count >= 64 || incomingChar == '\n') {
      buffer[count] = '\0';

      if (strstr(buffer, "$GPGGA")) {
        char *latitudeStart = strchr(buffer, ',') + 12;
        char *longitudeStart = strchr(latitudeStart, ',') + 5;

        if (latitudeStart && longitudeStart) {
          char *latitudeEnd = strchr(latitudeStart, ',');
          char *longitudeEnd = strchr(longitudeStart, ',');

          if (latitudeEnd && longitudeEnd) {
            *latitudeEnd = '\0';
            *longitudeEnd = '\0';

            latitude = atof(latitudeStart) / 100.0; 
            longitude = atof(longitudeStart) / 100.0;
            // latitude = 55.5555555555555;
            // longitude = 2.3999999999999;
          }
        }
      }

    count = 0;
    }
  }
}