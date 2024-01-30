#ifndef Lecture_Frein_Accel_h
#define Lecture_Frein_Accel_h

#include <Arduino.h>

class Lecture_Frein_Accel {
public:
    Lecture_Frein_Accel(int pinFrein, int pinAccel);
    void setup();
    void lireCapteurs();
    int getFr_Prcent();
    int getAc_Prcent();

private:
    int pinFrein_;
    int pinAccel_;
    int Fr_Prcent;
    int Ac_Prcent;
};

#endif
