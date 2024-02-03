#ifndef MFREQUENCE_H
#define MFREQUENCE_H

#include <Arduino.h>

class MFrequence
{
public:
    static MFrequence &getInstance()
    {
        static MFrequence instance; 
        return instance;
    }

    void setup();
    void loop();
    void initTimer(uint8_t ID, uint16_t Prescaler, uint16_t alarm);
    
private:
    MFrequence();
    MFrequence(const MFrequence &); 
    ~MFrequence();
    void operator=(const MFrequence &);

    friend void onTimer();
    friend void onFallingEdge();
};

void onTimer();
void onFallingEdge();

#endif