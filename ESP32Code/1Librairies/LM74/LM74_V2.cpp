#include "LM74_V2.h"
#include <SPI.h>

LM74::LM74(shiftReg &shiftRegister) : shiftRegister(shiftRegister)
{
}

void LM74::begin()
{
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);
    SPI.setClockDivider(SPI_CLOCK_DIV16);
}

float LM74::read(int selecteur) {
    uint16_t byte1 = SPI.transfer(0);
    uint16_t byte2 = SPI.transfer(0);
    shiftRegister.Selecteur_CS(selecteur); 
    uint16_t regbits = (byte1 << 8) + byte2;
    regbits = (regbits >> 3);
    float temp = regbits * 0.0625;
    return temp;
}


