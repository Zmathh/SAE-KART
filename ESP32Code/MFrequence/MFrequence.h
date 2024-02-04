#ifndef MFREQUENCE_H
#define MFREQUENCE_H

#include <Arduino.h>

class MFrequence
{
public:
    void setup();
    void loop();
    float getFreq();

private:
    const int LED = 21;
    const int SW = 38;
    const int GEN = 15;
    const int timerID = 0;
    const int preScaler = 8; // Timer 10MHz
    const int n = 20;

    volatile bool FlagPin = false;
    volatile uint16_t i = 0;
    volatile uint16_t temp = 0;
    volatile uint16_t temp2 = 0;
    volatile float temps = 0.0;
    volatile float freq = 0.0;
    volatile float moy = 0.0;
    volatile int l = 0;

    void IRAM_ATTR onFallingEdge(int timerID, int preScaler, int compareValue);
    void enableAlarm();
    void disableAlarm();
    void IRAM_ATTR onFallingEdge();
};

#endif