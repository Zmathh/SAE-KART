#include "Lecture_Frein_Accel.h"

Lecture_Frein_Accel::Lecture_Frein_Accel(int pinFrein, int pinAccel, float coefAccel, float coefFrein)
{
  _pinFrein = pinFrein;
  _pinAccel = pinAccel;
  _coefAccel = coefAccel;
  _coefFrein = coefFrein;
}

void Lecture_Frein_Accel::begin()
{
  pinMode(_pinFrein, INPUT);
  pinMode(_pinAccel, INPUT);
}

int Lecture_Frein_Accel::readFrein()
{
  return float((int)((float)((analogRead(_pinFrein)) / 4095.0) * 100.0)*_coefFrein);
}

int Lecture_Frein_Accel::readAccel()
{
  return float((int)((float)((analogRead(_pinAccel)) / 4095.0) * 100.0)*_coefAccel);
}