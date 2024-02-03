#include "CONFIG_H.h"

#if Activate_Ecran == 1
Ecran ecran;
#endif

#if Activate_LoRa == 1
const uint8_t dataPacketSize = sizeof(float) * 13 + sizeof(float) * 2; 
uint8_t dataPacket[dataPacketSize];
CModuleLoRa* pModuleLoRa = NULL;
float data[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
float latitude = 48.4423344;
float longitude = 1.496218;
#endif

#if Activate_ACCEL_FREIN == 1
Lecture_Frein_Accel lesLectures;
#endif

#if Activate_ShiftReg == 1
pinMode(SC,OUTPUT);
pinMode(CSN,OUTPUT);
pinMode(SIO,INPUT);
shiftReg shiftReg(CS_DAT, CS_CLK, CS_STRB);
#endif

#if Activate_Temperature == 1
LectTemp temperatureSensor(CS_CKL, CS_DAT, CS_STD); //// Vérifier les PINs
#endif

#if Activate_GPS == 1
GPS gps(GPS_Tx, GPS_Rx);
#endif

void setup()
{
    #if Activate_Serial == 1
    Serial.begin(VITESSE_SERIAL_DEBUG);  // Initialisation de la vitesse de la liaison série
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
    lesLectures.begin();  // Initialisation des capteurs
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

    #if Activate_Ecran == 1
    ecran.begin();
    #endif
}

void loop()
{
    #if Activate_GPS == 1
    gps.readData();
    Serial.print("Latitude: ");
    Serial.print(gps.latitude, 6);
    Serial.print(" Longitude: ");
    Serial.println(gps.longitude, 6);
    gps.flushBuffer();
    #endif

    #if Activate_ShiftReg == 1
    shiftReg.selectionTemp();
    #endif
    
    #if Activate_Temperature == 1
    float temperature = LectTemp.readTemperature(); // Lit la température du capteur
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    #endif
    
    #if Activate_ACCEL_FREIN == 1
    Serial.print("Frein : ");
    Serial.println(lesLectures.readFrein());
    Serial.print("Accel : ");
    Serial.println(lesLectures.readAccel());
    delay(500);
    Serial.println(lectureFreinAccel.getFr_Prcent());
    Serial.println(lectureFreinAccel.getAc_Prcent());
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
    delay(250);
    #endif

    #if Activate_Ecran == 1 
    ecran.refresh();
    #endif
    
    #if Activate_FREQ == 1
    MFreq.loop();
    float freq = MFreq.getFreq();
    #endif
}
