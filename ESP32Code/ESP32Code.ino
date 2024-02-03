#include "CONFIG_H.h"

// Var LoRa

// const uint8_t dataPacketSize = sizeof(float) * 13 + sizeof(float) * 2; 
// uint8_t dataPacket[dataPacketSize];

// LiquidCrystal_I2C lcd(0x27,20,4);

// //-------------------
// // Variable Numero de port
// //-------------------

// pinMode(SC,OUTPUT);
// pinMode(CSN,OUTPUT);
// pinMode(SIO,INPUT);

// //-------------------
// // Variables générales
// //-------------------

// Lecture_Frein_Accel lesLectures;

// shiftReg shiftReg(CS_DAT, CS_CLK, CS_STRB);

// LectTemp temperatureSensor(CS_CKL, CS_DAT, CS_STD); //// Vérifier les PINs

// CModuleLoRa* pModuleLoRa = NULL;

// GPS gps(GPS_Tx, GPS_Rx);

// float data[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
// float latitude = 48.4423344;
// float longitude = 1.496218;

//

void setup()
{
    //     //-------Serial----------------
    // Serial.begin(VITESSE_SERIAL_DEBUG);  // Initialisation de la vitesse de la liaison série

    //     //-------GPS-------------------
    // gps.begin();

    //     //-------shiftReg-----------
    // shiftReg.setup();

    //     //-------temperature-----------
    //     temperatureSensor.begin();

    //     ////-------Accelero/Frein--------
    //     lesLectures.begin();  // Initialisation des capteurs

    // Initialisation LoRa
    // pModuleLoRa = CModuleLoRa::GetInstance();
    // pModuleLoRa->init(16, 17);
    // pModuleLoRa->setConfig();
    // pModuleLoRa->getConfig();
    // pModuleLoRa->getInfo();

    //     // Initialisation ECRAN

    //     // Initialisation MFREQUENCE
    // MFreq.setup();

    //     // Initialisation Ecran
    //  ecran.setup();
}
// //----------------------------------------------------------------
void loop()
{
    //-----------GPS---------------
    // gps.readData();
    // Serial.print("Latitude: ");
    // Serial.print(gps.latitude, 6);
    // Serial.print(" Longitude: ");
    // Serial.println(gps.longitude, 6);
    // gps.flushBuffer();
    
    //----------shiftReg-----------

    // shiftReg.selectionTemp();

    //-------temperature-----------
    //     Mesure_temp(Lect, Somme);

    //-------Accelero/Frein--------
    //     Serial.print("Frein : ");
    //     Serial.println(lesLectures.readFrein());
    //     Serial.print("Accel : ");
    //     Serial.println(lesLectures.readAccel());
    //     delay(500);
    //     Serial.println(lectureFreinAccel.getFr_Prcent());
        // Serial.println(lectureFreinAccel.getAc_Prcent());

    //-------Envoi-LORA--------
        // for (int i = 0; i < 13; i++) {
        //     data[i] += 1.0;
        // }

        // latitude = latitude + 0.00001;
        // longitude = longitude + 0.00001;
        // memcpy(dataPacket, data, sizeof(float) * 13);
        // memcpy(dataPacket + sizeof(float) * 13, &latitude, sizeof(float));
        // memcpy(dataPacket + sizeof(float) * 13 + sizeof(float), &longitude, sizeof(float));
        // pModuleLoRa->radioTX(dataPacket, dataPacketSize);
        // delay(250);

    //--------ECRAN------------

    //     if(etat_PIT) {PIT_LCD();} //Si on reçoit alarme du stand (supervions) affichage du mot PIT sur l'écran
    //     else {
    //         SPEEDCOUNTER(speed);                                  //Gestion affichage vitesse
    //         TOPSPEED(speed);                                      //Gestion vitesse maximum
    //         BATTERY(tension_big_battery, tension_small_battery);  //Gestion batterie
    //         CHRONOMETER();                                        //Gestion chronomètre

    //         etat_clean = true;

    //         //A utiliser pour phase de test
    //         /*
    //         speed++;
    //         delay(200);
    //         */
    //     }

    //    float temperature = temperatureSensor.readTemperature(); // Lit la température du capteur
    //    Serial.print("Temperature: ");
    //    Serial.print(temperature);
    //    Serial.println(" C");
    
    //  MFreq.loop();
    //  float freq = MFreq.getFreq();
}
