#ifndef Mesure_Frequence_h
#define Mesure_Frequence_h

#include <Arduino.h>

class Mesure_Frequence
{
public:
  void Mesure_Frequence(int SW);
  void begin();
  void IRAM_ATTR onTimer();
  void IRAM_ATTR onFallingEdge();
  float Mesure();
  void initTimer(uint8_t ID, uint16_t Prescaler, uint16_t alarm);
  void enableAlarm();
  void : disableAlarm();

private:
  float Vitesse
};

#endif