#include "CONFIG_H.h"

#if Activate_LoRa == 1
const uint8_t dataPacketSize = sizeof(float) * 13 + sizeof(float) * 2;
uint8_t dataPacket[dataPacketSize];
CModuleLoRa *pModuleLoRa = NULL;
float data[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
float latitude = 48.4423344;
float longitude = 1.496218;
#endif

#if Activate_ACCEL_FREIN == 1
Lecture_Frein_Accel frein_accel(FREIN, ACCEL);
#endif

#if Activate_ShiftReg == 1
shiftReg shiftReg(CS_DAT, CS_CLK, CS_STRB);
#endif

#if Activate_Temperature == 1
LectTemp temperatureSensor(CS_CLK, CS_DAT, CS_STRB); //// Vérifier les PINs
#endif

#if Activate_GPS == 1
GPS gps(GPS_Tx, GPS_Rx);
#endif

#if Activate_FREQ == 1
MFrequence MFreq;
#endif

#if Activate_Ecran == 1
Ecran ecran;
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
    // delay(5000);
    Serial.println("Ecran initialisé");
#endif

#if Activate_ESP32Core == 1
    delay(1000);
    Serial.println("Starting to create tasks...");

    xTaskCreatePinnedToCore(
        coreTaskOne,   /* Function to implement the task */
        "coreTaskOne", /* Name of the task */
        10000,         /* Stack size in words */
        NULL,          /* Task input parameter */
        2,             /* Priority of the task */
        NULL,          /* Task handle. */
        taskCoreOne);  /* Core where the task should run */
    Serial.println("TaskOne Created");

    xTaskCreatePinnedToCore(
        coreTaskTwo,   /* Function to implement the task */
        "coreTaskTwo", /* Name of the task */
        10000,         /* Stack size in words */
        NULL,          /* Task input parameter */
        3,             /* Priority of the task */
        NULL,          /* Task handle. */
        taskCoreTwo);  /* Core where the task should run */
    Serial.println("TaskTwo Created");

    Serial.println("All Tasks created...");
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
    frein_accel.begin(); // Initialisation des capteurs
#endif

#if Activate_LoRa == 1
    pModuleLoRa = CModuleLoRa::GetInstance();
    pModuleLoRa->init(16, 17);
    pModuleLoRa->setConfig();
    pModuleLoRa->getConfig();
    pModuleLoRa->getInfo();
#endif

#if Activate_FREQ == 1
    MFreq.setup();
#endif
}

void coreTaskOne(void *pvParameters){ /////////////// LOOP main

    // #if Activate_Serial == 1
    //     String taskMessage = "running on core ";
    //     taskMessage = taskMessage + xPortGetCoreID();
    //     Serial.println(taskMessage);
    // #endif

  Serial.println("taskOne ON");
  delay(1000);

  while (true){

    Serial.println("taskOne");
          
    #if Activate_GPS == 1
            gps.readData();
            Serial.print("Latitude: ");
            Serial.print(gps.latitude, 6);
            Serial.print(" Longitude: ");
            Serial.println(gps.longitude, 6);
            gps.flushBuffer();
    #endif

    #if Activate_ShiftReg == 1
    for(int i=0;i<5;i++){
      shiftReg.Selecteur_CS(i);
    }
    delay(1);
    #endif

    #if Activate_Temperature == 1
            float temperature = LectTemp.readTemperature(); // Lit la température du capteur
            Serial.print("Temperature: ");
            Serial.print(temperature);
            Serial.println(" °C");
    #endif

    #if Activate_ACCEL_FREIN == 1
            Serial.print("Frein : ");
            Serial.println(frein_accel.readFrein());
            Serial.print("Accel : ");
            Serial.println(frein_accel.readAccel());
            delay(500);
            Serial.println(frein_accel.getFr_Prcent());
            Serial.println(frein_accel.getAc_Prcent());
    #endif

    #if Activate_LoRa == 1
            for (int i = 0; i < 13; i++)
            {
                data[i] += 1.0;
            }
            latitude = latitude + 0.00001;
            longitude = longitude + 0.00001;
            memcpy(dataPacket, data, sizeof(float) * 13);
            memcpy(dataPacket + sizeof(float) * 13, &latitude, sizeof(float));
            memcpy(dataPacket + sizeof(float) * 13 + sizeof(float), &longitude, sizeof(float));
            pModuleLoRa->radioTX(dataPacket, dataPacketSize);
            delay(250);
    #endif

    #if Activate_FREQ == 1
            MFreq.loop();
            float freq = MFreq.getFreq();
    #endif
  }
}

  void coreTaskTwo(void *pvParameters){ /////////////////////// LOOP écran
  #if Activate_Serial == 1
      Serial.println("taskTwo ON");
  #endif
  while (true){
    delay(1000);
    Serial.println("taskTwo");
    #if Activate_Ecran == 1
      ecran.refresh();
    #endif
    }
}

// void coreTaskTwo( void * pvParameters ){
//     #if Activate_Serial == 1
//         Serial.println("taskTwo ON");
//     #endif

//     while(true){
//         Serial.println("taskTwo");
//         delay(1000);
//     }
// }

void loop()
{ // NE SERT A RIEN !!!!

    //Serial.println("TaskLoop delay 10s ");
    delay(10000);
}
