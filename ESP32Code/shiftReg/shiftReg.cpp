#include "shiftReg.h"

shiftReg::shiftReg(uint8_t dataPin, uint8_t clockPin, uint8_t strobePin)
    : dataPin(dataPin), clockPin(clockPin), strobePin(strobePin)
{
    dataPin = dataPin;
    clockPin = clockPin;
    strobePin = strobePin;
}

void shiftReg::setup() 
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(strobePin, OUTPUT);

  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(strobePin, LOW);
}

void shiftReg::selectionTemp() 
{
  for (int capteur = 0; capteur < 5; capteur++) {
    Selecteur_CS(capteur);
  }
}

void shiftReg::Selecteur_CS(int capteur) 
{
  shiftOut(dataPin, clockPin, MSBFIRST, 1 << capteur);
  digitalWrite(strobePin, HIGH);
  digitalWrite(strobePin, LOW);
}