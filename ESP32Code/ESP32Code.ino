#include "CONFIG_H.h"  

#include "Petit code\Lecture_Frein_Accel\Lecture_Frein_Accel.h"

//-------------------
// Variable Numero de port
//-------------------



//-------------------
// Variables générales
//-------------------

Lecture_Frein_Accel lectureFreinAccel(FREIN, ACCEL);

void setup() {
    //-------Accelero/Frein--------
    lectureFreinAccel.setup();
    Serial.begin(VITESSE_SERIAL);  // Assurez-vous d'initialiser Serial si ce n'est pas déjà fait

    // Initialisez d'autres configurations si nécessaire
}

void loop() {
    //-------Accelero/Frein--------
    lectureFreinAccel.lireCapteurs();
    Serial.println(lectureFreinAccel.getFr_Prcent());
    Serial.println(lectureFreinAccel.getAc_Prcent());

}
