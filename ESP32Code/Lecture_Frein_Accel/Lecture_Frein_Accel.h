#ifndef Lecture_Frein_Accel_h
#define Lecture_Frein_Accel_h

#include <Arduino.h>
#include "Lecture_Frein_Accel.h"

class Lecture_Frein_Accel
{
public:
  Lecture_Frein_Accel(int pinFrein, int pinAccel);
  void begin();
  int readFrein();
  int readAccel();

private:
  int _pinFrein;
  int _pinAccel;
};

#endif