// config.h
#ifndef CONFIG_H_h
#define CONFIG_H_h

////////////////////////////////////////////////////////////////
// Déclaration des librairies  //////////////
////////////////////////////////////////////////////////////////

#include <arduino.h>

#include <Wire.h>

#include "1Librairies/SoftwareSerial/SoftwareSerial.cpp"

#include "1Librairies/Wire/wire.cpp"

#include "1Librairies/DFRobot_IICSerial/DFRobot_IICSerial.cpp"

// #include "1Librairies/LiquidCrystal_I2C/LiquidCrystal_I2C.cpp"



////////////////////////////////////////////////////////////////
// Déclaration des librairies programmes //////////////
////////////////////////////////////////////////////////////////

#include "Fonctions/Fonctions.cpp"

#include "ecran/ecran.cpp"

//#include "MFrequence/MFrequence.cpp"

#include "GPS_IIC/GPS_IIC.cpp"

#include "LectTemp/LectTemp.cpp"

#include "shiftReg/shiftReg.cpp"

#include "Lecture_Frein_Accel/Lecture_Frein_Accel.cpp"

#include "module_lora/module_lora.cpp"

////////////////////////////////////////////////////////////////
// CONFIGURATION //////////////
////////////////////////////////////////////////////////////////

#define VITESSE_SERIAL_DEBUG 115200

#define Activate_Serial 1
#define Activate_ESP32Core 1 // Activer Serial Debug pour comprendre
#define Activate_GPS_IIC 0
#define Activate_ShiftReg 0
#define Activate_Temperature 0
#define Activate_ACCEL_FREIN 0
#define Activate_LoRa 0
#define Activate_Ecran 0
#define Activate_FREQ 1

////////////////////////////////////////////////////////////////
// Déclaration Pins //////////////
////////////////////////////////////////////////////////////////

#define CS_STRB 0
#define LoRa_Tx 1
#define LoRa_Rx 3
#define CS_CLK 2
#define CS_DAT 4
#define RESET 5
#define Led_Alarme 15
#define TensionPetiteBat 17
#define uWire_CLK 18
#define uWire_SI_O 19
#define TensionGrandBat 13
#define I2C_SDA 21
#define I2C_SCL 22
#define LedSignal 23
#define ACCEL 25
#define FREIN 26
#define INT 32
#define Vitesse 33

// pour test capteur temps (temporaire)
#define SC_pin 33
#define CSN_pin 32
#define SIO_pin 25

#endif // CONFIG_H