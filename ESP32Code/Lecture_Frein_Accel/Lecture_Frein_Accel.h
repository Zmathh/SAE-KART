#ifndef Lecture_Frein_Accel_h
#define Lecture_Frein_Accel_h

#include <Arduino.h>
#include "Lecture_Frein_Accel.h"

class Lecture_Frein_Accel
{
public:
  Lecture_Frein_Accel(int pinFrein, int pinAccel, float coefAccel, float coefFrein);
  void begin();
  int readFrein();
  int readAccel();

private:
  int _pinFrein;
  int _pinAccel;
  float _coefAccel;
  float _coefFrein;
};

#endif