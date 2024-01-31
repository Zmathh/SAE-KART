#include "..\1Librairies\SoftwareSerial\SoftwareSerial.h"

#include "GPS.h"

GPS::GPS(uint8_t rxPin, uint8_t txPin) : gpsSerial(rxPin, txPin) {
  count = 0;
  isGPGGA = false;
}

void GPS::begin(uint32_t baudRate) {
  gpsSerial.begin(baudRate);
}

std::pair<float, float> GPS::readData() {
  float latitude = 0.0f, longitude = 0.0f;
  
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

          }
        }
      }

      count = 0;
    }
  }

  if (Serial.available()) {
    gpsSerial.write(Serial.read());
  }
  
  return {latitude, longitude};
}