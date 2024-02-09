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
  digitalWrite(strobePin, HIGH);
}

void shiftReg::Selecteur_CS(int capteur)
{

  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);
  int i = 0;
  bool bitenvoyer[8];

  for (int i = 0; i < 8; i++)
    bitenvoyer[i] = LOW;

  if (capteur != -1)
    bitenvoyer[capteur] = HIGH;

  Serial.println("------------------");

  for (i = 5; i >= 0; i--)
  {
    digitalWrite(clockPin, LOW);
    delay_Retard(2);
    if (bitenvoyer[i] == LOW)
      digitalWrite(dataPin, LOW);
    else
      digitalWrite(dataPin, HIGH);
    Serial.print(bitenvoyer[i]);
    delay_Retard(2);
    digitalWrite(clockPin, HIGH);
    delay_Retard(3);
  }

  digitalWrite(strobePin, HIGH);
  delay_Retard(1);
  digitalWrite(strobePin, LOW);
  delay_Retard(1);
  Serial.println("------------------");

  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);
}

void shiftReg::delay_Retard(int a)
{
  for (int i = 0; i < 100000 * a; i++)
  {
    __asm__("nop\n\t");
  }
}

/*

digitalWrite(strobePin, HIGH);
  delay(100);
  digitalWrite(strobePin, LOW);
  delay(100);
  */