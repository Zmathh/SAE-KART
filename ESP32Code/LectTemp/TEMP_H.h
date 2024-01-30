#ifndef TEMP_H
#define TEMP_H

#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class TEMP_H {
public:
    Mesure_temp();
    Attend();

  

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