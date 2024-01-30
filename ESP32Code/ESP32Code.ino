#include "CONFIG_H"  

#include "Lecture_Frein_Accel/Lecture_Frein_Accel.h"

//-------------------
// Variable Numero de port
//-------------------

#define FREIN 36
#define ACCEL 39

//-------------------
// Variables générales
//-------------------

Lecture_Frein_Accel lectureFreinAccel(FREIN, ACCEL);

void setup() {
    //-------Accelero/Frein--------
    lectureFreinAccel.setup();
    Serial.begin(115200);  // Assurez-vous d'initialiser Serial si ce n'est pas déjà fait

    // Initialisez d'autres configurations si nécessaire
}

void loop() {
    //-------Accelero/Frein--------
    lectureFreinAccel.lireCapteurs();
    Serial.println(lectureFreinAccel.getFr_Prcent());  // Utilisez les getters pour accéder aux valeurs
    Serial.println(lectureFreinAccel.getAc_Prcent());

    // Ajoutez le reste de votre code loop ici
}
