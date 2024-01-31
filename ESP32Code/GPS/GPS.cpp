 #include "..\1Librairies\SoftwareSerial\SoftwareSerial.h"

SoftwareSerial SoftSerial(17, 16);
char buffer[64];
int count = 0;
bool isGPGGA = false;




void GPS(){
if (SoftSerial.available()) {
      char incomingChar = SoftSerial.read();

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
              *latitudeEnd = '\0'; // Null-terminate the latitude string
              *longitudeEnd = '\0'; // Null-terminate the longitude string

              float latitude = atof(latitudeStart) / 100.0; // Convert and divide latitude by 100
              float longitude = atof(longitudeStart) / 100.0; // Convert and divide longitude by 100

              Serial.print("Latitude: ");
              Serial.print(latitude, 6); // Print with 6 decimal places
              Serial.print(", Longitude: ");
              Serial.println(longitude, 6); // Print with 6 decimal places
            }
          }
        }

        count = 0;
      }
    }

    if (Serial.available()) {
      SoftSerial.write(Serial.read());
    }
}