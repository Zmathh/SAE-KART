#include "CONFIG_H.h"  
#include "Lecture_Frein_Accel\Lecture_Frein_Accel.h"
#include "GPS\GPS.h"
#include "code_ecran\ECRAN_H.h"
#include "LectTemp\TEMP_H.h"

LiquidCrystal_I2C lcd(0x27,20,4);


//-------------------
// Variable Numero de port
//-------------------

pinMode(SC,OUTPUT);
pinMode(CSN,OUTPUT);
pinMode(SIO,INPUT);


//-------------------
// Variables générales
//-------------------

Lecture_Frein_Accel lectureFreinAccel(FREIN, ACCEL);

CModuleLoRa* pModuleLoRa = NULL;

float data[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0}; 
float latitude = 48.4423344;
float longitude = 1.496218;

void setup() {
    
    //-------Serial----------------
    Serial.begin(VITESSE_SERIAL);  // Initialisation de la vitesse de la liaison série

    //-------temperature-----------
    digitalWrite(CSN,HIGH);

    //-------Accelero/Frein--------
    lectureFreinAccel.setup();  // Initialisation des capteurs

    // Initialisation LoRa
    pModuleLoRa = CModuleLoRa::GetInstance();
    pModuleLoRa->init(16, 17);
    pModuleLoRa->setConfig();
    pModuleLoRa->getConfig();
    pModuleLoRa->getInfo();

    // Initialisation ECRAN
    lcd.init(); lcd.backlight();
    lcd.createChar(0, Eclair); lcd.createChar(1, Chrono); 
    lcd.createChar(4, BOT);    lcd.createChar(5, TOP);    lcd.createChar(6, FULL);
    lcd.createChar(7, BATTL);  lcd.createChar(3, BATTF);

}

void loop() {
    //-------temperature-----------
    Mesure_temp();
    //-------Accelero/Frein--------
    lectureFreinAccel.lireCapteurs();
    Serial.println(lectureFreinAccel.getFr_Prcent());
    Serial.println(lectureFreinAccel.getAc_Prcent());

    //-------Envoi-LORA--------
    for (int i = 0; i < 13; i++) {
        data[i] += 1.0;
    }

    latitude = latitude + 0.00001;
    longitude = longitude + 0.00001;
    memcpy(dataPacket, data, sizeof(float) * 7);
    memcpy(dataPacket + sizeof(float) * 7, &latitude, sizeof(float));
    memcpy(dataPacket + sizeof(float) * 7 + sizeof(float), &longitude, sizeof(float));
    pModuleLoRa->radioTX(dataPacket, dataPacketSize);
    
    //--------ECRAN------------

    if(etat_PIT) {PIT_LCD();} //Si on reçoit alarme du stand (supervions) affichage du mot PIT sur l'écran
    else {
        SPEEDCOUNTER(speed);                                  //Gestion affichage vitesse
        TOPSPEED(speed);                                      //Gestion vitesse maximum
        BATTERY(tension_big_battery, tension_small_battery);  //Gestion batterie
        CHRONOMETER();                                        //Gestion chronomètre

        etat_clean = true; 

        //A utiliser pour phase de test
        /*
        speed++; 
        delay(200);
        */
    }
}
