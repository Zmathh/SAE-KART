#ifndef Lecture_Frein_Accel_h
#define Lecture_Frein_Accel_h

#include <Arduino.h>

class Lecture_Frein_Accel
{
  public:
    Lecture_Frein_Accel(int pinFrein=36, int pinAccel=39);
    void begin();
    int readFrein();
    int readAccel();

  private:
    int _pinFrein;
    int _pinAccel;
};

#endif