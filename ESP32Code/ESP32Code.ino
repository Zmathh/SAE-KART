#include "CONFIG_H.h"  

//#include "Lecture_Frein_Accel/Lecture_Frein_Accel.h"

//-------------------
// Variables générales
//-------------------

//Lecture_Frein_Accel lectureFreinAccel(FREIN, ACCEL);

void setup() {
    
    //-------Serial--------
    Serial.begin(VITESSE_SERIAL);  // Initialisation de la vitesse de la liaison série

    //-------Accelero/Frein--------
   // lectureFreinAccel.setup();  // Initialisation des capteurs


    // Initialisez d'autres configurations si nécessaire
}

void loop() {
    //-------Accelero/Frein--------
  //  lectureFreinAccel.lireCapteurs();
  //  Serial.println(lectureFreinAccel.getFr_Prcent());
  //  Serial.println(lectureFreinAccel.getAc_Prcent());

}
