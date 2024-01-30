// MonCapteurs.cpp
#include "Lecture_Frein_Accel.h"

Lecture_Frein_Accel::Lecture_Frein_Accel(int pinFrein, int pinAccel) {
    pinFrein_ = pinFrein;
    pinAccel_ = pinAccel;
}

void Lecture_Frein_Accel::setup() {
    Serial.begin(115200);
    pinMode(pinFrein_, INPUT);
    pinMode(pinAccel_, INPUT);
}

void Lecture_Frein_Accel::lireCapteurs() {
    Fr_Prcent = (int)((float)(((analogRead(pinFrein_) * 3.3) / 4095) / 3.3) * 100);
    Ac_Prcent = (int)((float)(((analogRead(pinAccel_) * 3.3) / 4095) / 3.3) * 100);

    Serial.print("Frein : ");
    Serial.println(Fr_Prcent);
    Serial.print("Accel : ");
    Serial.println(Ac_Prcent);

    delay(500);
}
