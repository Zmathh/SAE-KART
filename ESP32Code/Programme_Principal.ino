#include CONFIG_H
#include <Arduino.h>

//-------------------
// Variable Numero de port
//-------------------

#define FREIN 36
#define ACCEL 39

//-------------------
// Variable géneral
//-------------------

//.....Accelero/Frain.....

void setup
{
    // General
    Serial.begin(VITESSE_SERIAL);

    //-------Accelero/Frain--------
    pinMode(FREIN, INPUT);
    pinMode(ACCEL, INPUT);
}

void loop
{
}
