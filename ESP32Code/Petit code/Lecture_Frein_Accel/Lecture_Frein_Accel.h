// MonCapteurs.h
#ifndef Lecture_Frein_Accel
#define Lecture_Frein_Accel

#include <Arduino.h>

class Lecture_Frein_Accel {
public:
    Lecture_Frein_Accel(int pinFrein, int pinAccel);
    void setup();
    void lireCapteurs();

private:
    int pinFrein_;
    int pinAccel_;
    int Fr_Prcent;
    int Ac_Prcent;
};

#endif
