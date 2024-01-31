#line 1 "C:\\Users\\Surface Mathis\\Desktop\\SAE-KART-1\\ESP32Code\\code_ecran\\code_ecran.h"
#ifdef ECRAN_H.h
#define ECRAN_H.h

#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class ECRAN_H {
public:
  NUMBER();
  CLEAN_COLUMN();
  CLEAN_LCD();
  CHRONOMETER();
  TOPSPEED();
  SPEEDCOUNTER();
  BATTERY();
  PIT_LCD();

private:
    byte Eclair[64];
    byte Chrono[64];
    byte BOT[64];
    byte TOP[64];
    byte FULL[64];
    byte BATTL[64];
    byte BATTF[64];
    char mid;
    char empty;
    bool running;
    unsigned long startTime;
    unsigned long elapsedTime; 
    unsigned long previousMillis_B;
    unsigned long previousMillis_L; 
    const long interval; 
    int speed_max;
    int etat_B;
    int etat_L; 
    bool etat_PIT;
    bool etat_clean; 
    int hundreds, tens, units;
    int speed; 
    float tension_big_battery; 
    float tension_small_battery; 
};

#endif
