#include <Arduino.h>

#define SERIAL 1
#define SELFTEST 0

#define LED 21

#define SW 23

#define GEN 15

#define timerID 0
#define preScaler 8 //Timer 10MHz


#define Diametre 26   
#define pi 3.1416
#define Nb_Ecrou 6
#define Perimetre (Diametre*pi)/Nb_Ecrou
#define Coefcm_s_to_km_h 36/1000
#define CoefFreq_Vitesse Coefcm_s_to_km_h*Perimetre

hw_timer_t *My_timer = NULL;
TaskHandle_t Loop0;

boolean FlagPin = false;

uint16_t timrValue = 0;

float Vitesse;

uint16_t i = 0, temp = 0, temp2 = 0;

float temps = 0., freq = 0., moy = 0;
int n = 20, l = 0;

void IRAM_ATTR onTimer() {

  //digitalWrite(LED, !digitalRead(LED));
  i++;
  temp2 = timerRead(My_timer);

}

void IRAM_ATTR onFallingEdge() {
  
  FlagPin = !FlagPin;

}

void setup() {

#if SERIAL == 1
  Serial.begin(115200);
  while(!Serial){;;}
#endif
  pinMode(LED, OUTPUT);
  pinMode(GEN, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  
  initTimer(timerID, preScaler, 100);
  
  attachInterrupt(SW, &onFallingEdge, FALLING);


}


void loop() {

  if (FlagPin) {
    enableAlarm();
    attachInterrupt(SW, &onFallingEdge, FALLING);
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
    attachInterrupt(SW, &onFallingEdge, FALLING);

    Vitesse= freq*CoefFreq_Vitesse;
#if SERIAL == 1  
    if (temp > 0) {
      Serial.print("B");
      Serial.println(Vitesse);
    }
#endif  
  }



}

void initTimer(uint8_t ID, uint16_t Prescaler, uint16_t alarm) {
  My_timer = timerBegin(ID, Prescaler, true);
  timerAttachInterrupt(My_timer, &onTimer, true);
  timerAlarmWrite(My_timer, alarm, true);
  timerAlarmEnable(My_timer);
}

void enableAlarm() {
  timerAlarmEnable(My_timer);
}

void disableAlarm() {
  timerAlarmDisable(My_timer);
}