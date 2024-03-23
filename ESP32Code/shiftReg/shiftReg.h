#ifndef shiftReg_H
#define shiftReg_H

#include <Arduino.h>

class shiftReg
{
public:
    shiftReg(int dataPin, int clockPin, int strobePin);
    void setup();
    void Selecteur_CS(int capteur);
    void delay_Retard(int a);


private:
    const int dataPin;
    const int clockPin;
    const int strobePin;
};

#endif