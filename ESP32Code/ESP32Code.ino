#include "CONFIG_H.h"

Fonctions Fonctions;


#if Activate_LoRa == 1
SoftwareSerial SoftSerial(17, 16);
const uint8_t dataPacketSize = (sizeof(float) * 13) + (sizeof(char) * 10 * 2) + (sizeof(int) * 2);
uint8_t dataPacket[dataPacketSize];
CModuleLoRa *pModuleLoRa = NULL;
#endif

#if Activate_ACCEL_FREIN == 1
Lecture_Frein_Accel frein_accel(FREIN, ACCEL, COEFACCEL, COEFFREIN);
#endif

#if Activate_ShiftReg == 1
    shiftReg shiftRegister(CS_DAT, CS_CLK, CS_STRB); 
#endif

#if Activate_Temperature == 1
    LM74 lm74_1(shiftRegister);  
    float temperature1 = 0.0 ,temperature2 = 0.0 ,temperature3 = 0.0 ,temperature4 = 0.0 ,temperature5 = 0.0 ;
#endif

#if Activate_GPS_IIC == 1
GPS_IIC gps;
#endif

#if Activate_FREQ == 1

    #define SW 25

    #define timerID 0
    #define preScaler 8 //Timer 10MHz

    double oldfreq, buffer ;

  int milli_freq = 0;
  int previous_milli_freq = 0;
  int comptage_freq = 0;
  float frequence = 0;
  int interval_freq = 1000;
  float interval_sec_freq = interval_freq/1000;
  

    hw_timer_t *My_timer = NULL;

    boolean FlagPin = false;

    uint16_t i = 0, temp = 0, temp2 = 0;

    int n = 50 , y = 0;

    float temps = 0., freq = 0., moy= 0., resultmoy = 0.;

    void IRAM_ATTR onTimer() {

    //digitalWrite(LED, !digitalRead(LED));
    i++;
    temp2 = timerRead(My_timer);

    }

    void IRAM_ATTR onFallingEdge() {
    
    comptage_freq++;

    }
    //MFrequence MFrequence;
#endif

#if Activate_FREQ == 1
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
#endif

// #if Activate_BUTT == 1

//   boolean FlagStart = false;
//   boolean FlagMenu  = false;
//   boolean FlagRst   = false;

//   void IRAM_ATTR onStart() {

//     FlagStart = true;

//   }

//   void IRAM_ATTR onMenu() {

//     FlagMenu = true;

//   }

//   void IRAM_ATTR onReset() {

//     FlagRst = true;

//   }
// #endif

#if Activate_Ecran == 1
Ecran ecran(I2C_SCL, I2C_SDA);
#endif

#if Activate_ESP32Core == 1
static uint8_t taskCoreOne = 0;
static uint8_t taskCoreTwo = 1;
#endif

void setup()
{
#if Activate_Serial == 1
    Serial.begin(VITESSE_SERIAL_DEBUG); // Initialisation de la vitesse de la liaison série
    Serial.print("Serial began @ ");
    Serial.println(VITESSE_SERIAL_DEBUG);
#endif

#if Activate_Ecran == 1
    ecran.BV12 = 12;       // Batterie 12V
    ecran.BV48 = 48;       // Batterie 48V
    ecran.speed = 42;      // Vitesse
    ecran.running = false; // Bouton PIT
    ecran.begin();
// Fonctions.delay_Retard(5000);
#if Activate_Serial == 1
    Serial.println("Ecran initialisé");
#endif
#endif

#if Activate_ESP32Core == 1
// Fonctions.delay_Retard(1000);
#if Activate_Serial == 1
    Serial.println("Starting to create tasks...");
#endif
    xTaskCreatePinnedToCore(
        coreTaskOne,   /* Function to implement the task */
        "coreTaskOne", /* Name of the task */
        10000,         /* Stack size in words */
        NULL,          /* Task input parameter */
        0,             /* Priority of the task */
        NULL,          /* Task handle. */
        taskCoreOne);  /* Core where the task should run */
#if Activate_Serial == 1
    Serial.println("TaskOne Created");
#endif
    xTaskCreatePinnedToCore(
        coreTaskTwo,   /* Function to implement the task */
        "coreTaskTwo", /* Name of the task */
        10000,         /* Stack size in words */
        NULL,          /* Task input parameter */
        1,             /* Priority of the task */
        NULL,          /* Task handle. */
        taskCoreTwo);  /* Core where the task should run */
#if Activate_Serial == 1
    Serial.println("TaskTwo Created");

    Serial.println("All Tasks created...");
#endif
#endif

#if Activate_GPS_IIC == 1
    gps.begin();
    Fonctions.delay_Retard(100);
#endif

#if Activate_ShiftReg == 1
    shiftRegister.setup();
#endif

#if Activate_Temperature == 1
    lm74_1.begin();
#endif

#if Activate_ACCEL_FREIN == 1
    frein_accel.begin(); // Initialisation des capteurs
#endif

#if Activate_LoRa == 1
    pModuleLoRa = CModuleLoRa::GetInstance();
    pModuleLoRa->init(16, 17);
    pModuleLoRa->setConfig();
#endif

#if Activate_FREQ == 1
    

  pinMode(Vitesse, INPUT_PULLUP);
  
  //initTimer(timerID, preScaler, 100);
  
  attachInterrupt(SW, &onFallingEdge, FALLING);

#endif

// #if Activate_BUTT == 1

//   pinMode(START_STOP     , INPUT_PULLUP);
//   pinMode(BP_MENU        , INPUT_PULLUP);
//   pinMode(BP_RESET_CHRONO, INPUT_PULLUP);

//   attachInterrupt(START_STOP     , &onStart, FALLING);
//   attachInterrupt(BP_MENU        , &onMenu , FALLING);
//   attachInterrupt(BP_RESET_CHRONO, &onReset, FALLING);

// #endif

#if Activate_pinMode == 1
  pinMode(TensionPetiteBat,INPUT);
  pinMode(TensionGrandBat,INPUT);
#endif

}

void coreTaskOne(void *pvParameters)
{ /////////////// LOOP main

#if Activate_Serial == 1
  //     String taskMessage = "running on core ";
    //     taskMessage = taskMessage + xPortGetCoreID();
    //     Serial.println(taskMessage);

    Serial.println("taskOne ON");
#endif
    while (true)
    {
        milli_freq = millis();
            if (milli_freq - previous_milli_freq >= interval_freq)
            {
                previous_milli_freq = milli_freq;
                frequence = comptage_freq/(interval_sec_freq);
                comptage_freq = 0;
                // Serial.println(frequence);
            }

}
    }
        

void coreTaskTwo(void *pvParameters)
{ /////////////////////// LOOP écran
#if Activate_Serial == 1
    Serial.println("taskTwo ON");
#endif
    while (true)
    {
#if Activate_Ecran == 0
        //Fonctions.delay_Retard(1000);
#endif
        //Serial.println("taskTwo");
#if Activate_Ecran == 1
 //Serial.print("ecran on");
  // #if Activate_BUTT == 1
  //   if (FlagMenu) {
  //     ecran.incrementDisplay();
  //     Serial.println("-Menu-");
  //     FlagMenu = false;
  //   }
  //   if (FlagStart) {
  //     ecran.incrementStart();
  //     Serial.println("-Start-");
  //     FlagStart= false;
  //   }
  //   if (FlagRst) {
  //     ecran.incrementReset();
  //     Serial.println("-Reset-");
  //     FlagRst = false;
  //   }
  //   //ecran.etat_menu=1;
  // #endif
  //Serial.print("oui");
        ecran.etat_menu=1;
        //ecran.speed=resultmoy;
        #if Activate_FREQ == 1
          ecran.speed=((frequence/6) * coeffvitesse);
          //ecran.speed = frequence; 
       #endif
        ecran.BV12=(analogRead(TensionPetiteBat)*1.8/1975)*coeffpb; //14V max Au chargement de la batterie
        // ecran.BV48=(51-(51*((analogRead(TensionPetiteBat)*3.3)/4095.))*3.3);
        // (analogRead(TensionGrandBat)); //52 V max ?
        //ecran.BV48=2;
        ecran.refresh();

#endif

         //Fonctions.delay_Retard(1000); // possible watchdog si retiré sans aucun programme
#if Activate_Serial == 1
        //Serial.println("taskOne");
#endif

#if Activate_GPS_IIC == 1 
        // gps.getdata();
        //latitude_float;
#endif

#if Activate_ShiftReg == 1   
#endif

#if Activate_Temperature == 1
        shiftRegister.Selecteur_CS(-1);
        temperature1 = lm74_1.read(0); // Read from sensor 0
        temperature2 = lm74_1.read(1); // Read from sensor 0
        temperature3 = lm74_1.read(2);
        temperature4 = lm74_1.read(3);
        temperature5 = lm74_1.read(4);
        ecran.temp_moteur = temperature1;
        ecran.temp_bat1 = temperature2;
        ecran.temp_bat2 = temperature3;
        ecran.temp_bat3 = temperature4;
        ecran.temp_bat4 = temperature5;
        // Serial.print("Sensor 1: ");
        // Serial.print(temp_1);
        // Serial.print("°C  /  ");
        // Serial.print("Sensor 2: ");
        // Serial.print(temp_2);
        // Serial.print("°C  /  ");
        // Serial.print("Sensor 3: ");
        // Serial.print(temp_3);
        // Serial.print("°C  /  ");
        // Serial.print("Sensor 4: ");
        // Serial.print(temp_4);
        // Serial.print("°C  /  ");
        // Serial.print("Sensor 5: ");
        // Serial.print(temp_5);
        // Serial.println("°C");
        
        
#endif

#if Activate_ACCEL_FREIN == 1
        // Serial.print("Frein : ");
        //ecran.BV12=(frein_accel.readFrein());
        // Serial.print("Accel : ");
        //ecran.BV48=(frein_accel.readAccel());
        //Fonctions.delay_Retard(500);
        //Serial.println(frein_accel.getFr_Prcent());
        //Serial.println(frein_accel.getAc_Prcent());
#endif

#if Activate_LoRa == 1
  float floatsToSend[] = {
    float(random(100, 8000) /100.0),
    float(random(100, 8000) /100.0),
    float(random(100, 8000) /100.0),
    float(random(100, 8000) /100.0),
    float(random(100, 8000) /100.0),
    float(random(0.0, 9999)/100.0),
    float(random(0.0, 9999)/100.0),
    float(random(11.0, 1290)/100.0),
    float(random(44.0, 4890)/100.0),
    float(random(200.0, 39990)/100.0),
    float(random(0, 99)),
    float(random((-18000), 18000)/100.0),
    float(random((-9000), 9000)/100.0),
      
  };

  memcpy(dataPacket, floatsToSend, sizeof(float) * 13);
  strcpy((char *)(dataPacket + sizeof(float) * 13), "2024-01-31");
  strcpy((char *)(dataPacket + sizeof(float) * 13 + sizeof(char) * 10), "1706717755");
  int integersToSend[] = {
      random(0, 1),
      random(0, 1)
  };
  memcpy(dataPacket + sizeof(float) * 13 + sizeof(char) * 10 * 2, integersToSend, sizeof(int) * 2);
  pModuleLoRa->radioTX(dataPacket, dataPacketSize);
#endif

    }
}

void loop()
{ 
#if Activate_FREQ == 1
/* if (FlagPin) {
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

    temps = (temp * 100) + temp2 ; 

    freq = 10000000. / temps; 
      
  }
  attachInterrupt(SW, &onFallingEdge, FALLING);

  if (temp > 0 && freq < 2500 ) {
      
    if (y != n){ 
        // Serial.print(moy);
        // Serial.print("+");
        // Serial.print(freq);
        // Serial.print("=");
      moy += freq;
      y++;
    //  Serial.println(moy);
   } else if (y == n){
      resultmoy = moy/n;
      moy=0;
      y=0;
        // Serial.println("mise a zero-------------------------------------------");
    }
    #if Activate_Serial == 1
      Serial.print("Hz =");
      Serial.println(resultmoy);
    #endif 
    }
 
  } */
    
    // milli_freq = millis();
    // if (milli_freq - previous_milli_freq >= interval_freq)
    // {
    //     previous_milli_freq = milli_freq;
    //     frequence = comptage_freq/(interval_sec_freq);
    //     comptage_freq = 0;
    //     //Serial.println(frequence);
    // }
#endif
}


