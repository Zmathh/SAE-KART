// config.h
#ifndef CONFIG_H_h
#define CONFIG_H_h

////////////////////////////////////////////////////////////////

#include <arduino.h>
#include "1Librairies\SoftwareSerial\SoftwareSerial.h"
#include "1Librairies\SoftwareSerial\SoftwareSerial.cpp"

///////////////////////////////////////////////////////////////

// #include "ecran/ecran.h"
// #include "ecran/ecran.cpp"

//#include "MFrequence/MFrequence.h"
//#include "MFrequence/MFrequence.cpp"

#include "GPS\GPS.h"
#include "GPS\GPS.cpp"

#include "shiftReg\shiftReg.h"
#include "shiftReg\shiftReg.cpp"

#include "LectTemp\LectTemp.h"
#include "LectTemp\LectTemp.cpp"

#include "Lecture_Frein_Accel\Lecture_Frein_Accel.cpp"
#include "Lecture_Frein_Accel\Lecture_Frein_Accel.h"

#include "module_lora\module_lora.h"
#include "module_lora\module_lora.cpp"

////////////////////////////////////////////////////////////////
 // CONFIGURATION //////////////
////////////////////////////////////////////////////////////////

#define VITESSE_SERIAL_DEBUG 115200

#define Activate_Serial 0
#define Activate_GPS 0
#define Activate_ShiftReg 0
#define Activate_Temperature 0
#define Activate_ACCEL_FREIN 0
#define Activate_LoRa 0
#define Activate_Ecran 0
#define Activate_FREQ 0

// PINs

#define FREIN 26
#define ACCEL 25
#define TensionGrandBat 13
#define TensionPetiteBat 17
#define LedSignal 23
#define I2C_SCL 22
#define i2C_SDA 21
#define uWire_SI_O 19
#define uWire_CLK 18
#define GPS_Tx 17
#define GPS_Rx 16
#define LoRa_Tx 1
#define LoRa_Rx 3
#define Led_Alarme 15
#define CS_STRB 0
#define CS_CLK 2
#define CS_DAT 4
#define RESET 5
#define INT 32
#define Vitesse 33



#endif // CONFIG_H
