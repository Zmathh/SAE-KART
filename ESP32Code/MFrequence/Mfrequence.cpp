#include "Mfrequence.h"
#include <driver/timer.h>

Mfrequence::Mfrequence() {
  i = 0;
  temp = 0;
  temp2 = 0;
  temps = 0.;
  freq = 0.;
  moy = 0;
  n = 20;
  l = 0;
}

Mfrequence* Mfrequence::getInstance() {
  static Mfrequence instance;
  return &instance;
}

void Mfrequence::staticOnFallingEdge() {
  // Call the member function onFallingEdge of the current instance
  Mfrequence::getInstance()->onFallingEdge();
}

void Mfrequence::setup() {
    
  initTimer(timerID, preScaler, 100);
  attachInterrupt(SW, staticOnFallingEdge, FALLING);
}

void Mfrequence::loop() {
  if (FlagPin) {
    enableAlarm();
    attachInterrupt(SW, staticOnFallingEdge, FALLING);
  } else {
    detachInterrupt(SW);
    for(int k = 0; k < 1000; k++){;;}
    disableAlarm();
    for(int k = 0; k < 1000; k++){;;}
    temp = i;
    i = 0;
    if (temp != 0) {
      if (l < n) {
        moy += temp;
        l++;
      } else {
        l = 0;
        moy = moy/n;
        temps = (temp * 100) + temp2 ; 
        freq = 10000000. / temps; 
      }
    }
    attachInterrupt(SW, staticOnFallingEdge, FALLING);
  #if Activate_Serial == 1  
      if (temp > 0) {
        Serial.print("B");
        Serial.println(freq);
      }
  #endif  
    }
  }

void Mfrequence::initTimer(uint8_t ID, uint16_t Prescaler, uint16_t alarm) {
  My_timer = timerBegin(ID, Prescaler, true);
  timerAttachInterrupt(My_timer, reinterpret_cast<void (*)(void*)>(&Mfrequence::onTimer), this);
  timerAlarmWrite(My_timer, alarm, true);
  timerAlarmEnable(My_timer);
}

  void Mfrequence::enableAlarm() {
    timerAlarmEnable(My_timer);
  }

  void Mfrequence::disableAlarm() {
    timerAlarmDisable(My_timer);
  }