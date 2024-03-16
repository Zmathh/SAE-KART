#include "GPS_IIC.h"

char messageBuffer[64];
int messageIndex = 0;

GPS_IIC::GPS_IIC() : iicSerial1(Wire, SUBUART_CHANNEL_1, 1, 1) {}

void GPS_IIC::begin() {
    iicSerial1.begin(9600);
}

void GPS_IIC::getdata() {
    char latitude[15];
    char longitude[15];
    
    while (iicSerial1.available()) {
        char incomingChar = iicSerial1.read();
        if (incomingChar == '$') {
            messageIndex = 0;
        }
        messageBuffer[messageIndex++] = incomingChar;
        if (incomingChar == '\n') {
            messageBuffer[messageIndex] = '\0'; 
            if (strncmp(messageBuffer, "$GPGGA", 6) == 0 || strncmp(messageBuffer, "$GPRMC", 6) == 0) {
                memset(latitude, 0, sizeof(latitude));
                memset(longitude, 0, sizeof(longitude));

                char* token = strtok(messageBuffer, ",");
                int index = 0;
                while (token != NULL) {
                    if (index == 2) {
                        strncpy(latitude, token, sizeof(latitude) - 1);
                    } else if (index == 4) {
                        strncpy(longitude, token, sizeof(longitude) - 1);
                    }
                    token = strtok(NULL, ",");
                    index++;
                }
                float latitude_float = atof(latitude) / 100;
                float longitude_float = atof(longitude) / 100;

                Serial.print("Latitude: ");
                Serial.println(latitude_float, 6);
                Serial.print("Longitude: ");
                Serial.println(longitude_float, 6);
            }
            messageIndex = 0;
        }
    }
}