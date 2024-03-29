// config.h
#ifndef CONFIG_H_h
#define CONFIG_H_h

////////////////////////////////////////////////////////////////
// Déclaration des librairies  //////////////
////////////////////////////////////////////////////////////////

#include <arduino.h>

#include "1Librairies/Wire/Wire.cpp"

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

#include "Lecture_Frein_Accel/Lecture_Frein_Accel.cpp"

#include "module_lora/module_lora.cpp"

#include "shiftReg/shiftReg.cpp"

#include "LM74/LM74_V2.cpp"

////////////////////////////////////////////////////////////////
// CONFIGURATION //////////////
////////////////////////////////////////////////////////////////

#define VITESSE_SERIAL_DEBUG 115200

#define Activate_Serial 1
#define Activate_ESP32Core 1 // Activer Serial Debug pour comprendre
#define Activate_GPS_IIC 1
#define Activate_ShiftReg 1
#define Activate_Temperature 1
#define Activate_ACCEL_FREIN 1
#define Activate_LoRa 1
#define Activate_Ecran 1
#define Activate_FREQ 1
#define Activate_BUTT 1

////////////////////////////////////////////////////////////////
// Déclaration Pins //////////////
////////////////////////////////////////////////////////////////

#define I2C_SDA 21
#define I2C_SCL 22

#define LoRa_Tx 17
#define LoRa_Rx 16

#define CS_STRB 0
#define CS_CLK 2
#define CS_DAT 4

#define START_STOP 5
#define BP_MENU 33
#define BP_RESET_CHRONO 32

#define uWire_CLK 18
#define uWire_SI_O 19

#define TensionPetiteBat 12
#define TensionGrandBat 13
#define LedSignal 15
#define ACCEL 14
#define FREIN 27
#define Signal_INT 26
#define Vitesse 25

// pour test capteur temps (temporaire)
// #define SC_pin 32
// #define CSN_pin 25
// #define SIO_pin 33

#define COEFACCEL 1.5
#define COEFFREIN 1
#define PI 3.14159265358979323846
#define coeffpb 11.5/1.5
#define coeffgb 0
#define coeffvitesse 2 * PI * 0.15 * 3.6


#define RESET 35

#endif // CONFIG_H