#ifndef GPS_IIC_H
#define GPS_IIC_H


class GPS_IIC {
public:
    GPS_IIC();
    void begin();
    void getdata();
    float latitude;
    float longitude;
    float latitude_float;
    float longitude_float;
    int go;
    char incomingChar;

private:
    DFRobot_IICSerial iicSerial1;
    String getValue(String data, char separator, int index);
    char buffer[64];
    int count;
    bool isGPGGA;
    char messageBuffer[80];
    int messageIndex;
    
};

#endif
