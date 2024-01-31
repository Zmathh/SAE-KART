// config.h
#ifndef CONFIG_H_h
#define CONFIG_H_h

////////////////////////////////////////////////////////////////


#include "GPS\GPS.h"
#include "GPS\GPS.cpp"

#include "code_ecran\ECRAN_H.h"
#include "code_ecran\code_ecran.cpp"

#include "LectTemp\TEMP_H.h"
#include "LectTemp\LectTemp.cpp"

#include "Lecture_Frein_Accel\Lecture_Frein_Accel.cpp"
#include "Lecture_Frein_Accel\Lecture_Frein_Accel.h"

////////////////////////////////////////////////////////////////
 // CONFIGURATION //////////////
////////////////////////////////////////////////////////////////
#define VITESSE_SERIAL_1 115200
#define VITESSE_SERIAL_2 9600



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
#define GPS_Tx2 17
#define GPS_Rx2 16
#define LoRa_Tx2 1
#define LoRa_Rx2 3
#define Led_Alarme 15
#define CS_STD 0
#define CS_CKL 2
#define CS_DAT 4
#define RESET 5
#define INT 32
#define Vistesse 33

// Add other configurations or declarations if needed

#endif // CONFIG_H
