#ifndef GPS_IIC_H
#define GPS_IIC_H

#include <DFRobot_IICSerial.h>

class GPS_IIC {
public:
    GPS_IIC();
    void begin();
    void getdata();
    float getLatitude();
    float getLongitude();

private:
    DFRobot_IICSerial iicSerial1;
    String getValue(String data, char separator, int index);
    char buffer[64];
    int count;
    bool isGPGGA;
    float latitude;
    float longitude;
};

#endif
