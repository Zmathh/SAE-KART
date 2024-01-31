#line 1 "C:\\Users\\Arno\\Desktop\\SAE-KART\\ESP32Code\\LectTemp\\LectTemp.h"
#ifndef LectTemp_h
#define LectTemp_h

#include <Arduino.h>
#include "..\1Librairies\SoftwareSerial\SoftwareSerial.h"

class LectTemp {
public:
    LectTemp(int SC_pin, int CSN_pin, int SIO_pin);
    void begin();
    float readTemperature();

private:
    int SC_pin;
    int CSN_pin;
    int SIO_pin;
    int Somme;
    bool Lect[16]; // I assumed that as you checking 16 positions, this will be an array of 16 elements.
    int i;
    int puiss;
};
#endif