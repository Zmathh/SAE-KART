#include "shiftReg.h"

shiftReg::shiftReg(int dataPin, int clockPin, int strobePin)
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

void shiftReg::Selecteur_CS(int capteur)
{
  bool SerieBits[5];
  for (int i = 0; i < 5; i++)
  {
    SerieBits[i] = LOW;
  }

  SerieBits[capteur] = HIGH;

  for (int i = 0; i < 5; i++)
  {
    digitalWrite(clockPin, LOW);
    delay(1);

    digitalWrite(clockPin, HIGH);
    delay(1);
    // Serial.print(SerieBits[i]);
  }

  // shiftOut(dataPin, clockPin, MSBFIRST, 1 << capteur);
  Serial.print("......");
}

/*

digitalWrite(strobePin, HIGH);
  delay(100);
  digitalWrite(strobePin, LOW);
  delay(100);
  */