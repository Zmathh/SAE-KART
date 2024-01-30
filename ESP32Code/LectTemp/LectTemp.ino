#include <Arduino.h>


int SC=6;
int CSN=5;
int SIO=4;
bool Lect[20];
int i;
float Somme=0;
int a;
float puiss;

void setup() {
}

void loop() {
}


void Mesure_temp(){
  for(i=0;i<16;i++){
    digitalWrite(SC,HIGH);
    Attend();
    Lect[i]=digitalRead(SIO);
    digitalWrite(SC,LOW);
    Attend();
  }
  for(i=0;i<16;i++){
    digitalWrite(SC,HIGH);
    Attend();
    digitalWrite(SC,LOW);
    Attend();
  }
  digitalWrite(CSN,HIGH);
  delay(500);
  for(i=1;i<14;i++){
    puiss=128/pow(2,(i-1));
    Somme=Somme+Lect[i]*puiss;
  }
  return Lect, Somme
}

void Attend(){
  for(a=0;a<30000;a++){
  __asm__("nop\n\t");
  }
}