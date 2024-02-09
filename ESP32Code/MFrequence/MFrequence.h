#ifndef Mfrequence_h
#define Mfrequence_h

#include <Arduino.h>

class Mfrequence {
  public:
    Mfrequence();
    void setup();
    void loop();
    static Mfrequence* getInstance();

  private:
    #define SW 38

    #define GEN 15

    #define timerID 0
    #define preScaler 8 //Timer 10MHz

    static void IRAM_ATTR staticOnFallingEdge();

    hw_timer_t* My_timer;
    boolean FlagPin;
    uint16_t timrValue;
    uint16_t i, temp, temp2;
    float temps, freq, moy;
    int n, l;

    void IRAM_ATTR onTimer();
    void IRAM_ATTR onFallingEdge();
    void initTimer(uint8_t ID, uint16_t Prescaler, uint16_t alarm);
    void enableAlarm();
    void disableAlarm();
};

#endif