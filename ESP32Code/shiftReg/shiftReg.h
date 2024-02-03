#ifndef shiftReg_H
#define shiftReg_H

#include <Arduino.h>

class shiftReg
{
public:
    shiftReg(uint8_t dataPin, uint8_t clockPin,uint8_t strobePin);
    void setup();
    void selectionTemp();
    
  


private:
    const int dataPin;
    const int clockPin;
    const int strobePin;
    void Selecteur_CS(int capteur);
};

#endif