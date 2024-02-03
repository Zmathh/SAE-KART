// Ecran.h

#ifndef Ecran_h
#define Ecran_h

#include <Arduino.h>
#include <Wire.h> 


class Ecran
{
  public:
    Ecran();

    void setup();
    void loop();

  private:
    void NUMBER(int x, int y);
    void CLEAN_COLUMN(int x);
    void CLEAN_LCD();
    void CHRONOMETER();
    void TOPSPEED(int speed);
    void SPEEDCOUNTER(int speed);
    void BATTERY(float tension_big_battery, float tension_small_battery);
    void PIT_LCD();

    // +
};

#endif