#ifndef LectTemp_h
#define LectTemp_h

#include <Arduino.h>

class LectTemp {
public:
  LectTemp(int SC_pin, int CSN_pin, int SIO_pin);
  void begin();
  float readTemperature();
private:
  int SC_pin;
  int CSN_pin;
  int SIO_pin;
  bool Lect[20];
  int i;
  float Somme;
  int a;
  float puiss;
  void delayMicrosecondsInline(unsigned int us);
};

#endif