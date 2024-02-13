#include "CONFIG_H.h"



#if Activate_LoRa == 1
const uint8_t dataPacketSize = sizeof(float) * 13 + sizeof(float) * 2; 
uint8_t dataPacket[dataPacketSize];
CModuleLoRa* pModuleLoRa = NULL;
float data[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
float latitude = 48.4423344;
float longitude = 1.496218;
#endif

#if Activate_ACCEL_FREIN == 1
Lecture_Frein_Accel frein_accel(FREIN, ACCEL);
#endif

#if Activate_ShiftReg == 0

shiftReg shiftReg(CS_DAT, CS_CLK, CS_STRB);
#endif

#if Activate_Temperature == 1
LectTemp temperatureSensor(SC_pin, CSN_pin, SIO_pin); //// Vérifier les PINs
#endif

#if Activate_GPS == 1
GPS gps(I2C_SCL, I2C_SDA);
#endif

#if Activate_FREQ == 1

    float freq;

  
    #define SW 17

    #define timerID 0
    #define preScaler 8 //Timer 10MHz


    hw_timer_t* My_timer;
    boolean FlagPin;
    uint16_t timrValue;
    uint16_t i, temp, temp2;
    float temps, moy;
    int n, l;

    void IRAM_ATTR onTimer() {

    //digitalWrite(LED, !digitalRead(LED));
    i++;
    temp2 = timerRead(My_timer);

    }

    void IRAM_ATTR onFallingEdge() {
    
    FlagPin = !FlagPin;

    }
    //MFrequence MFrequence;
#endif

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
        Serial.begin(VITESSE_SERIAL_DEBUG);  // Initialisation de la vitesse de la liaison série
        Serial.print("Serial began @ ");
        Serial.println(VITESSE_SERIAL_DEBUG);
    #endif

    #if Activate_Ecran == 1
        ecran.BV12 = 12; // Batterie 12V
        ecran.BV48 = 48; // Batterie 48V
        ecran.speed = 42; // Vitesse 
        ecran.running = false; // Bouton PIT
        ecran.begin();
        //Fonction.delay_Retard(5000);
        #if Activate_Serial == 1
            Serial.println("Ecran initialisé");
        #endif
    #endif

    #if Activate_ESP32Core == 1 
        //Fonction.delay_Retard(1000);
        #if Activate_Serial == 1
            Serial.println("Starting to create tasks...");
        #endif
        xTaskCreatePinnedToCore(
                            coreTaskOne,    /* Function to implement the task */
                            "coreTaskOne",  /* Name of the task */
                            10000,          /* Stack size in words */
                            NULL,           /* Task input parameter */
                            0,              /* Priority of the task */
                            NULL,           /* Task handle. */
                            taskCoreOne);   /* Core where the task should run */
        #if Activate_Serial == 1
            Serial.println("TaskOne Created");
        #endif
        xTaskCreatePinnedToCore(
                            coreTaskTwo,    /* Function to implement the task */
                            "coreTaskTwo",  /* Name of the task */
                            10000,          /* Stack size in words */
                            NULL,           /* Task input parameter */
                            1,              /* Priority of the task */
                            NULL,           /* Task handle. */
                            taskCoreTwo);   /* Core where the task should run */
        #if Activate_Serial == 1
            Serial.println("TaskTwo Created");
        
            Serial.println("All Tasks created...");
        #endif
    #endif
        
    #if Activate_GPS == 1
        gps.begin();
    #endif

    #if Activate_ShiftReg == 1
        shiftReg.setup();
    #endif

    #if Activate_Temperature == 1
        temperatureSensor.begin();
    #endif

    #if Activate_ACCEL_FREIN == 1
        frein_accel.begin();  // Initialisation des capteurs
    #endif

    #if Activate_LoRa == 1
        pModuleLoRa = CModuleLoRa::GetInstance();
        pModuleLoRa->init(9, 10);
        pModuleLoRa->setConfig();
        pModuleLoRa->getConfig();
        pModuleLoRa->getInfo();
    #endif

    #if Activate_FREQ == 1
        // MFrequence.begin();
        pinMode(SW, INPUT_PULLUP);
        
        initTimer(timerID, preScaler, 100);
  
        attachInterrupt(SW, &onFallingEdge, FALLING);
    #endif

}


void coreTaskOne( void * pvParameters ){/////////////// LOOP main

    #if Activate_Serial == 1 
    //     String taskMessage = "running on core ";
    //     taskMessage = taskMessage + xPortGetCoreID();
    //     Serial.println(taskMessage);
    
    
        Serial.println("taskOne ON");
    #endif
    while(true){
        //Fonction.delay_Retard(1000); // possible watchdog si retiré
        #if Activate_Serial == 1
            Serial.println("taskOne");
        #endif

        #if Activate_GPS == 1
            gps.readData();
            Serial.print("Latitude: ");
            Serial.print(gps.latitude, 6);
            Serial.print(" Longitude: ");
            Serial.println(gps.longitude, 6);
            gps.flushBuffer();
        #endif

        #if Activate_ShiftReg == 1
          shiftReg.Selecteur_CS(1);
          shiftReg.delay_Retard(10);
          shiftReg.Selecteur_CS(2);
          shiftReg.delay_Retard(10);
          shiftReg.Selecteur_CS(3);
          shiftReg.delay_Retard(10);
          shiftReg.Selecteur_CS(4);
          shiftReg.delay_Retard(10);
          shiftReg.Selecteur_CS(5);
          shiftReg.delay_Retard(10);
        #endif
        
        #if Activate_Temperature == 1
            temperatureSensor.readTemperature();
            float temperature = temperatureSensor.temperature; // Lit la température du capteur
            Serial.print("Temperature: ");
            Serial.print(temperature);
            Serial.println(" °C");
        #endif
        
        #if Activate_ACCEL_FREIN == 1
            Serial.print("Frein : ");
            Serial.println(frein_accel.readFrein());
            Serial.print("Accel : ");
            Serial.println(frein_accel.readAccel());
            Fonction.delay_Retard(500);
            Serial.println(frein_accel.getFr_Prcent());
            Serial.println(frein_accel.getAc_Prcent());
        #endif

        #if Activate_LoRa == 1
            for (int i = 0; i < 13; i++) {
                data[i] += 1.0;
            }
            latitude = latitude + 0.00001;
            longitude = longitude + 0.00001;
            memcpy(dataPacket, data, sizeof(float) * 13);
            memcpy(dataPacket + sizeof(float) * 13, &latitude, sizeof(float));
            memcpy(dataPacket + sizeof(float) * 13 + sizeof(float), &longitude, sizeof(float));
            pModuleLoRa->radioTX(dataPacket, dataPacketSize);
            Fonction.delay_Retard(250);
        #endif

        #if Activate_FREQ == 1
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
            
            }



            //MFrequence.get();
            // float freq = MFrequence.freq;
            Serial.println(freq);
            shiftReg.delay_Retard(100);
        #endif
    }
}



void coreTaskTwo( void * pvParameters ){ /////////////////////// LOOP écran
    #if Activate_Serial == 1 
        Serial.println("taskTwo ON");
    #endif
    while(true){
        #if Activate_Ecran == 0
            //Fonction.delay_Retard(1000);
            shiftReg.delay_Retard(1000);
        #endif
        Serial.println("taskTwo");
        #if Activate_Ecran == 1 
            ecran.refresh();
            
        #endif
    }
}

void loop(){ // NE SERT A RIEN !!!!
    #if Activate_Serial == 1
        Serial.println("TaskLoop delay 10s ");
    #endif
Fonction.delay_Retard(10000);
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