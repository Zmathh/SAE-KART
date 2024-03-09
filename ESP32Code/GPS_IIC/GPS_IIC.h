#ifndef GPS_IIC_H
#define GPS_IIC_H


class GPS_IIC {
public:
    GPS_IIC();
    void begin();
    void getdata();
    float latitude;
    float longitude;

private:
    DFRobot_IICSerial iicSerial1;
    String getValue(String data, char separator, int index);
};

#endif
