#include <DFRobot_IICSerial.h>
#include "GPS_IIC.h"


GPS_IIC::GPS_IIC (){
  DFRobot_IICSerial iicSerial1(Wire, SUBUART_CHANNEL_1, 1, 1);
}

void GPS_IIC::begin() {
  iicSerial1.begin(9600);
}

void GPS_IIC::getdata() {
  char c;
  static String line = "";

  if(iicSerial1.available()) {
    c = iicSerial1.read();
    line += c;
    if (c == '\n') {
      if (line.startsWith("$GPGGA")) {
        String latitudeStr = getValue(line, ',', 2);
        String longitudeStr = getValue(line, ',', 4);
        float latitude = atof(latitudeStr.c_str()) / 100.0;
        float longitude = atof(longitudeStr.c_str()) / 100.0;
      }
      line = "";
    }
  }
}

String GPS_IIC::getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
