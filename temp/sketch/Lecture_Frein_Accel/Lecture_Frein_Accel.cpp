#line 1 "C:\\Users\\Arno\\Desktop\\SAE-KART\\ESP32Code\\Lecture_Frein_Accel\\Lecture_Frein_Accel.cpp"
#include "Lecture_Frein_Accel.h"
#include "..\1Librairies\SoftwareSerial\SoftwareSerial.h"

Lecture_Frein_Accel::Lecture_Frein_Accel(int pinFrein, int pinAccel)
{
  _pinFrein = pinFrein;
  _pinAccel = pinAccel;
}

void Lecture_Frein_Accel::begin()
{
  pinMode(_pinFrein, INPUT);
  pinMode(_pinAccel, INPUT);
}

int Lecture_Frein_Accel::readFrein()
{
  return (int) ((float) ((analogRead(_pinFrein) * 3.3) / 4095) * 100);
}

int Lecture_Frein_Accel::readAccel()
{
  return (int) ((float) ((analogRead(_pinAccel) * 3.3) / 4095) * 100);
}