#include "MFrequence.h"

//Déclarations et autres codes d'initialisation...

float temps = 0., freq = 0., moy = 0;
int n = 20, l = 0;

//...


void MFrequence::setup(){
  //Votre code setup() ici
}

void MFrequence::loop(){
  //Votre code loop() ici, sans le contenu en relation avec la fréquence

  if(temp > 0){
    freq = getFreq();
  }
}

float MFrequence::getFreq(){
  float frq = 0.;
  if(FlagPin) {
    enableAlarm();
    attachInterrupt(SW, &onFallingEdge, FALLING);
  }
  else {
    detachInterrupt(SW);
    for(int k = 0; k < 1000; k++){;;}
    disableAlarm();
    for(int k = 0; k < 1000; k++){;;}
    temp = i;
    i = 0;
    if(temp != 0) {
      if(l < n) {
        moy += temp;
        l++;
      }
      else {
        l = 0;
        moy = moy/n;
        temps = (temp * 100) + temp2 ; 
        frq = 10000000. / temps; 
      }
    }
    attachInterrupt(SW, &onFallingEdge, FALLING);  
  }
  return frq;
}

//...

MFrequence MFreq;