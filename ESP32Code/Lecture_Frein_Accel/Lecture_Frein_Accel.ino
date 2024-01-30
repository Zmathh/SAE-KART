#include "Lecture_Frein_Accel.h"

Lecture_Frein_Accel::Lecture_Frein_Accel(int pinFrein, int pinAccel) {
    pinFrein_ = pinFrein;
    pinAccel_ = pinAccel;
}

void Lecture_Frein_Accel::setup() {
    pinMode(pinFrein_, INPUT);
    pinMode(pinAccel_, INPUT);
    // Initialisez d'autres configurations si nécessaire
}

void Lecture_Frein_Accel::lireCapteurs() {
    Fr_Prcent = (int)((float)(((analogRead(pinFrein_) * 3.3) / 4095) / 3.3) * 100);
    Ac_Prcent = (int)((float)(((analogRead(pinAccel_) * 3.3) / 4095) / 3.3) * 100);
    // Ajoutez d'autres fonctionnalités de lecture si nécessaire
}

