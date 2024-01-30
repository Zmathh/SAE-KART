#ifndef TEMP_H
#define TEMP_H

#include <Arduino.h>
#include <Wire.h> 
#include "..\1Librairies\LiquidCrystal_I2C\LiquidCrystal_I2C.h"

class TEMP_H {
public:
    TEMP_H();     
    void Attend(); 

private:
    int SC;
    int CSN;
    int SIO;
    bool Lect[20];
    int i;
    float Somme;
    int a;
    float puiss;
};

#endif