#include "MFrequence.h"

void IRAM_ATTR onTimer() {
  //digitalWrite(LED, !digitalRead(LED));
  MFrequence.i++;
  MFrequence.temp2 = timerRead(MFrequence.My_timer);
}

void IRAM_ATTR onFallingEdge() {
  MFrequence.FlagPin = !MFrequence.FlagPin;
}

void MFrequence::setup() {
  // pinMode(LED, OUTPUT);
  // pinMode(GEN, OUTPUT);
  // pinMode(SW, INPUT_PULLUP);
    
  initTimer(timerID, preScaler, 100);
    
  attachInterrupt(SW, &MFrequence.onFallingEdge, MFrequence.FALLING);
}

void MFrequence::loop() {
  if (temp > 0) {
    freq = getFreq();
  }
}

float MFrequence::getFreq() {
  if (FlagPin) {
    enableAlarm();
    attachInterrupt(SW, &MFrequence.onFallingEdge, MFrequence.FALLING);
  } else {
    detachInterrupt(SW);
    for (int k = 0; k < 1000; k++) {
      // Do nothing
    }
    disableAlarm();
    for (int k = 0; k < 1000; k++) {
      // Do nothing
    }
    temp = i;
    i = 0;
    if (temp != 0) {
      if (l < n) {
        moy += temp;
        l++;
      } else {
        l = 0;
        moy = moy / n;
        temps = (temp * 100) + temp2;
        freq = 10000000. / temps;
      }
    }
    attachInterrupt(SW, &MFrequence.onFallingEdge, MFrequence.FALLING);
  }
  return freq;
}

void enableAlarm() {
  timerAlarmEnable(MFrequence.My_timer);
}

void disableAlarm() {
  timerAlarmDisable(MFrequence.My_timer);
}