#include "CONFIG_H.h"

Fonctions Fonctions;

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
LectTemp temperatureSensor(SC_pin, CSN_pin, SIO_pin); //// Vérifier les PINs
#endif

#if Activate_GPS_IIC == 1
GPS_IIC gps;
#endif

#if Activate_FREQ == 1


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
    pModuleLoRa->init(9, 10);
    pModuleLoRa->setConfig();
    pModuleLoRa->getConfig();
    pModuleLoRa->getInfo();
#endif

#if Activate_FREQ == 1
    
  pinMode(GEN, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  
  initTimer(timerID, preScaler, 100);
  
  attachInterrupt(SW, &onFallingEdge, FALLING);

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
        // Fonctions.delay_Retard(1000); // possible watchdog si retiré sans aucun programme
#if Activate_Serial == 1
        Serial.println("taskOne");
#endif

#if Activate_GPS_IIC == 1 
        gps.getdata();
#endif

#if Activate_ShiftReg == 1

        if (Serial.available() > 0)
        {
            // read the incoming byte:

            // say what you got:
            switch (Serial.read())
            {
            case 48: // 0
                shiftReg.Selecteur_CS(-1);
                break;
            case 49: // 1
                shiftReg.Selecteur_CS(0);
                break;
            case 50: // 2
                shiftReg.Selecteur_CS(1);
                break;
            case 51: // 1
                shiftReg.Selecteur_CS(2);
                break;
            case 52: // 0
                shiftReg.Selecteur_CS(3);
                break;
            case 53: // 1
                shiftReg.Selecteur_CS(4);
                break;
            }
        }
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
        Fonctions.delay_Retard(500);
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
        Fonctions.delay_Retard(250);
#endif

#if Activate_FREQ == 1
    if (FlagPin) {
        enableAlarm();
        attachInterrupt(SW, &onFallingEdge, FALLING);
    }
    else {
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
        #if Activate_Serial == 1  
            if (temp > 0) {
            Serial.print("B");
            Serial.println(freq);
            }
        #endif  
    }
#endif
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
        Fonctions.delay_Retard(1000);
#endif
        Serial.println("taskTwo");
#if Activate_Ecran == 1
        ecran.refresh();

#endif
    }
}

void loop()
{ // NE SERT A RIEN !!!!
}


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