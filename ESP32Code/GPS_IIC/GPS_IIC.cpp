#include "GPS_IIC.h"


GPS_IIC::GPS_IIC() : iicSerial1(Wire, SUBUART_CHANNEL_1, 1, 1) {}

void GPS_IIC::begin() {
    Serial.begin(9600);
    iicSerial1.begin(9600);
}

void GPS_IIC::getdata() {
    if (iicSerial1.available()) {
        char incomingChar = iicSerial1.read();

        if (incomingChar == '$') {
            count = 0;
            isGPGGA = false;
        }

        buffer[count] = incomingChar;
        count++;

        if (count >= 64 || incomingChar == '\n') {
            buffer[count] = '\0';

            if (strstr(buffer, "$GPGGA")) {
                isGPGGA = true;
            }

            if (isGPGGA) {
                char *latitudeStart = strchr(buffer, ',') + 12;
                char *longitudeStart = strchr(latitudeStart, ',') + 5;

                if (latitudeStart && longitudeStart) {
                    char *latitudeEnd = strchr(latitudeStart, ',');
                    char *longitudeEnd = strchr(longitudeStart, ',');

                    if (latitudeEnd && longitudeEnd) {
                        *latitudeEnd = '\0'; // Null-terminate the latitude string
                        *longitudeEnd = '\0'; // Null-terminate the longitude string

                        latitude = atof(latitudeStart) / 100.0; // Convert and divide latitude by 100
                        longitude = atof(longitudeStart) / 100.0; // Convert and divide longitude by 100
                    }
                }
            }
            count = 0;
            isGPGGA = false;
        }
    }
}

float GPS_IIC::getLatitude() {
    return latitude;
}

float GPS_IIC::getLongitude() {
    return longitude;
}
