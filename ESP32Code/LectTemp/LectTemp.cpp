#include "LectTemp.h"

LectTemp::LectTemp(int SC_pin, int CSN_pin, int SIO_pin) {
  this->SC_pin = SC_pin;
  this->CSN_pin = CSN_pin;
  this->SIO_pin = SIO_pin;
}

void LectTemp::begin() {
  pinMode(SC_pin, OUTPUT);
  pinMode(CSN_pin, OUTPUT);
  pinMode(SIO_pin, INPUT);
  digitalWrite(CSN_pin, HIGH);
  Serial.println("Ready");
}

float LectTemp::readTemperature() {
  Somme = 0;
  digitalWrite(CSN_pin, LOW);

  for (i = 0; i < 16; i++) {
    digitalWrite(SC_pin, HIGH);
    delayMicrosecondsInline(5); // Attente d'environ 5 microsecondes
    Lect[i] = digitalRead(SIO_pin);
    digitalWrite(SC_pin, LOW);
    delayMicrosecondsInline(5); // Attente d'environ 5 microsecondes
  }

  for (i = 0; i < 16; i++) {
    digitalWrite(SC_pin, HIGH);
    delayMicrosecondsInline(5); // Attente d'environ 5 microsecondes
    digitalWrite(SC_pin, LOW);
    delayMicrosecondsInline(5); // Attente d'environ 5 microsecondes
  }

  digitalWrite(CSN_pin, HIGH);
  delay(500);

  for (i = 1; i < 14; i++) {
    puiss = 128 / pow(2, (i - 1));
    Somme = Somme + Lect[i] * puiss;
  }

  return Somme;
}