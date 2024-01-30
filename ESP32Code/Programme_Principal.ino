#include CONFIG_H

#include "Lecture_Frein_Accel.h"
#include <Arduino.h>

//-------------------
// Variable Numero de port
//-------------------

#define FREIN 36
#define ACCEL 39

//-------------------
// Variables génerales
//-------------------

MonCapteurs mesCapteurs(FREIN, ACCEL);

void setup
{
    //-------Accelero/Frein--------
    Lecture_Frein_Accel.setup();
}

void loop
{
    //-------Accelero/Frein--------
    Lecture_Frein_Accel.lireCapteurs();
    Serial.println(Lecture_Frein_Accel.Fr_Prcent)
    Serial.println(Lecture_Frein_Accel.Ac_Prcent)
}
