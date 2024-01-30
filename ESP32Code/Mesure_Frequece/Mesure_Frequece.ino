#include <Arduino.h>

#define SERIAL 1
#define SELFTEST 0

#define LED 21

#define SW 38

#define GEN 15

#define timerID 0
#define preScaler 8 //Timer 10MHz

hw_timer_t *My_timer = NULL;
TaskHandle_t Loop0;

boolean FlagPin = false;

uint16_t timrValue = 0;

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

#if SELFTEST == 1
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Loop0code,   /* Task function. */
                    "Loop0",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Loop0,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  //delay(500); 
#endif

}

#if SELFTEST == 1
void Loop0code( void * pvParameters ){
  Serial.print("Loop0 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(GEN, HIGH);
    delay(10);
    digitalWrite(GEN, LOW);
    delay(10);
  } 
bite
}
#endif
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
#if SERIAL == 1  
    if (temp > 0) {
      Serial.print("B");
      Serial.println(freq);
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