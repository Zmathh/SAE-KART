// MonCapteurs.cpp
#include "Lecture_Frein_Accel.h"
#include CONFIG_H.h

Lecture_Frein_Accel::Lecture_Frein_Accel(int pinFrein, int pinAccel) {
    pinFrein_ = pinFrein;
    pinAccel_ = pinAccel;
}

void Lecture_Frein_Accel::setup() {
    Serial.begin(VITESSE_SERIAL);
    pinMode(pinFrein_, INPUT);
    pinMode(pinAccel_, INPUT);
}

void Lecture_Frein_Accel::lireCapteurs() {
    Fr_Prcent = (int)((float)(((analogRead(pinFrein_) * 3.3) / 4095) / 3.3) * 100);
    Ac_Prcent = (int)((float)(((analogRead(pinAccel_) * 3.3) / 4095) / 3.3) * 100);
    delay(500);
}
