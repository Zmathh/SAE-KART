#include "GPS.h"
#include "..\1Librairies\Wire\Wire.cpp"

GPS::GPS (int I2C_SCL, int I2C_SDA)  {
  this->I2C_SCL = I2C_SCL;
  this->I2C_SDA = I2C_SDA;
  buffer[64];
  count = 0;
  isGPGGA = false;
}

void GPS::begin() {
  Wire.begin();
}

void GPS::flushBuffer() {
  if (latitude != 0.0 || longitude != 0.0) {
    memset(buffer, 0, sizeof(buffer));
  }
}

void GPS::readData() {
  if (Wire.available()) {
    char incomingChar = Wire.read();

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
}