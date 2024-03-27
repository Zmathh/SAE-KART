#ifndef GPS_H
#define GPS_H



class GPS
{
public:
  GPS(int I2C_SCL, int I2C_SDA);
  int I2C_SCL;
  int I2C_SDA;
  
  void begin();
  void readData();
  float latitude;
  float longitude;
  void flushBuffer();


private:
  SoftwareSerial gpsSerial;
  char buffer[64];
  int count;
  bool isGPGGA;
};

#endif