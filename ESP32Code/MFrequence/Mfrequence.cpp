    #include "MFrequence.h"

    
    // hw_timer_t* My_timer;
    // boolean FlagPin;
    // uint16_t timrValue;
    // uint16_t i, temp, temp2;
    // float temps, freq, moy;
    // int n, l;



// void IRAM_ATTR onTimer() {

//   //digitalWrite(LED, !digitalRead(LED));
//   i++;
//   temp2 = timerRead(My_timer);

// }

// void IRAM_ATTR onFallingEdge() {
  
//   FlagPin = !FlagPin;

// }

// void MFrequence::begin() {

  

// }


// void MFrequence::get() {

  // if (FlagPin) {
  //   enableAlarm();
  //   attachInterrupt(SW, &onFallingEdge, FALLING);
  // } else {
  //   detachInterrupt(SW);
  //   for(int k = 0; k < 1000; k++){;;}
  //   disableAlarm();
  //   for(int k = 0; k < 1000; k++){;;}
  //   temp = i;
  //   i = 0;
  //   if (temp != 0) {
  //     if (l < n) {
  //       moy += temp;
  //       l++;
  //     } else {
  //       l = 0;
  //       moy = moy/n;
  //       temps = (temp * 100) + temp2 ; 
  //       freq = 10000000. / temps; 
  //     }
  //   }
  //   attachInterrupt(SW, &onFallingEdge, FALLING);
 
  // }



// }

// void MFrequence::initTimer(uint8_t ID, uint16_t Prescaler, uint16_t alarm) {
//   My_timer = timerBegin(ID, Prescaler, true);
//   timerAttachInterrupt(My_timer, &onTimer, true);
//   timerAlarmWrite(My_timer, alarm, true);
//   timerAlarmEnable(My_timer);
// }

// void MFrequence::enableAlarm() {
//   timerAlarmEnable(My_timer);
// }

// void MFrequence::disableAlarm() {
//   timerAlarmDisable(My_timer);
// }