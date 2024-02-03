#include <Wire.h> 
#include "ecran.h"



Ecran::Ecran() : lcd(0x20, 16, 2) {}

void Ecran::begin() {
  lcd.begin();
  lcd.backlight();
  //Serial.begin(9600);
  
  lcd.createChar(0, Eclair);
  lcd.createChar(1, Chrono);
  lcd.createChar(4, BOT);
  lcd.createChar(5, TOP);
  lcd.createChar(6, FULL);
  lcd.createChar(7, BATTL);
  lcd.createChar(3, BATTF);
}

void Ecran::NUMBER(int x, int y) {//Permet l'affichage des chiffres 0 à 9
  lcd.setCursor(8,3); lcd.print("km/hr");

  switch (x) {

    //Affiche du chiffre 0
    case 0:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(6);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(6);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(6);
    lcd.setCursor((y+1),1); lcd.write(empty);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(6);
    lcd.setCursor((y+1),2); lcd.write(4);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;
    
    //Affiche du chiffre 1
    case 1:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(6);
    lcd.setCursor((y+1),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(6);
    lcd.setCursor((y+1),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(6);
    lcd.setCursor((y+1),2); lcd.write(empty);
    break;

    //Affiche du chiffre 2
    case 2:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(5);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(6);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(6);
    lcd.setCursor((y+1),1); lcd.write(5);
    lcd.setCursor((y+2),1); lcd.write(5);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(6);
    lcd.setCursor((y+1),2); lcd.write(4);
    lcd.setCursor((y+2),2); lcd.write(4);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;

    //Affiche du chiffre 3
    case 3:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(5);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(6);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.print(mid);
    lcd.setCursor((y+1),1); lcd.print(mid);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(4);
    lcd.setCursor((y+1),2); lcd.write(4);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;

    //Affiche du chiffre 4
    case 4:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(6);
    lcd.setCursor((y+1),0); lcd.write(empty);
    lcd.setCursor((y+2),0); lcd.write(6);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(6);
    lcd.setCursor((y+1),1); lcd.write(4);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2); lcd.write(empty);
    lcd.setCursor((y+1),2); lcd.write(empty);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;

    //Affiche du chiffre 5
    case 5:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(6);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(5);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(5);
    lcd.setCursor((y+1),1); lcd.write(5);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(4);
    lcd.setCursor((y+1),2); lcd.write(4);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;

    //Affiche du chiffre 6
    case 6:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(6);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(5);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(6);
    lcd.setCursor((y+1),1); lcd.write(5);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(6);
    lcd.setCursor((y+1),2); lcd.write(4);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;

    //Affiche du chiffre 7
    case 7:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(5);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(6);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(empty);
    lcd.setCursor((y+1),1); lcd.write(empty);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(empty);
    lcd.setCursor((y+1),2); lcd.write(empty);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;

    //Affiche du chiffre 8
    case 8:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(6);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(6);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(6);
    lcd.setCursor((y+1),1); lcd.write(mid);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(6);
    lcd.setCursor((y+1),2); lcd.write(4);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;

    //Affiche du chiffre 9
    case 9:
    lcd.setCursor((y-1),0); lcd.write(empty);
    lcd.setCursor(y,0);     lcd.write(6);
    lcd.setCursor((y+1),0); lcd.write(5);
    lcd.setCursor((y+2),0); lcd.write(6);
    lcd.setCursor((y+3),0); lcd.write(empty);
    lcd.setCursor((y-1),1); lcd.write(empty);
    lcd.setCursor(y,1);     lcd.write(6);
    lcd.setCursor((y+1),1); lcd.write(4);
    lcd.setCursor((y+2),1); lcd.write(6);
    lcd.setCursor((y+3),1); lcd.write(empty);
    lcd.setCursor((y-1),2); lcd.write(empty);
    lcd.setCursor(y,2);     lcd.write(4);
    lcd.setCursor((y+1),2); lcd.write(4);
    lcd.setCursor((y+2),2); lcd.write(6);
    lcd.setCursor((y+3),2); lcd.write(empty);
    break;}}

void Ecran::CLEAN_COLUMN(int x) {//Permet de nettoyer une colonne pour optimiser l'affichage de la vitesse
  lcd.setCursor(x,0); lcd.write(empty);
  lcd.setCursor(x,1); lcd.write(empty);
  lcd.setCursor(x,2); lcd.write(empty);}

void Ecran::CLEAN_LCD() {//Permet de nettoyer l'ensemble de l'écran (optimisation : lcd.clear)
  for(int i =0; i<=19; i++) {
    lcd.setCursor(i,0); lcd.write(empty);
    lcd.setCursor(i,1); lcd.write(empty);
    lcd.setCursor(i,2); lcd.write(empty);
    lcd.setCursor(i,3); lcd.write(empty);}}
  

void Ecran::CHRONOMETER() {
  lcd.setCursor(2, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.print("00:00");
  
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command == "start") {
      if (!running) {
        startTime = millis() - elapsedTime;
        running = true;
      }
    } else if (command == "stop") {
      if (running) {
        elapsedTime = millis() - startTime;
        running = false;
      }
    } else if (command == "reset") {
      elapsedTime = 0;
      running = false;
    }
  }
  
  if (running) {
    unsigned long currentTime = millis();
    elapsedTime = currentTime - startTime;
  }
  
  int minutes = elapsedTime / 60000;
  int seconds = (elapsedTime % 60000) / 1000;
  
  lcd.setCursor(0, 1);
  
  if (minutes < 10) {
    lcd.print("0");
  }
  lcd.print(minutes);
  
  lcd.print(":");
  
  if (seconds < 10) {
    lcd.print("0");
  }
  lcd.print(seconds);
}

void Ecran::TOPSPEED(int x) {//Permet d'afficher la vitesse max atteinte
  lcd.setCursor(2,2); lcd.write(0);
  if(x > speed_max) {speed_max = x;}
  if(speed_max >= 100) {lcd.setCursor(1,3); lcd.print(speed_max);}
  else if(speed_max < 10) 
          if(speed_max == 0) {lcd.setCursor(1,3); lcd.print("N-D");}
          else {lcd.setCursor(1,3); lcd.print("00"); lcd.setCursor(3,3); lcd.print(speed_max);}
       else {lcd.setCursor(1,3); lcd.print("0"); lcd.setCursor(2,3); lcd.print(speed_max);}} 

void Ecran::SPEEDCOUNTER(int x) {//Permet la gestion de l'affichage de la vitesse (fonctionne avec la fonction Ecran::NUMBER)
  hundreds = x / 100; 
  x %= 100; 
  tens = x / 10; 
  units = x % 10; 

  //A utiliser en phase de test
  /*
  if(hundreds == 1) {x += 100;} //A utiliser quand phase de test
  if(x >= 150) {etat_PIT = true;}
  */

  if(hundreds == 0) {
    Ecran::CLEAN_COLUMN(6); Ecran::CLEAN_COLUMN(14); //Clean colonne 6 et 14 qyand on passe de 100 ves <100
    if(tens <= 1){
      if(tens == 0) {
        if(units == 1) {Ecran::CLEAN_COLUMN(7); Ecran::CLEAN_COLUMN(8); Ecran::CLEAN_COLUMN(12); Ecran::CLEAN_COLUMN(13); Ecran::NUMBER(units, 10);} 
        else {Ecran::CLEAN_COLUMN(7); Ecran::CLEAN_COLUMN(13); Ecran::NUMBER(units, 9);}}
      if(tens == 1) {
        if(units == 1) {Ecran::CLEAN_COLUMN(7); Ecran::CLEAN_COLUMN(13); Ecran::NUMBER(units, 11); Ecran::NUMBER(tens, 9);}
        else {Ecran::NUMBER(units, 10); Ecran::NUMBER(tens, 8);}}}
    if(tens >= 2) {
      if(units == 1) {Ecran::NUMBER(tens, 8); Ecran::NUMBER(units, 12);} 
      else {Ecran::NUMBER(tens, 7); Ecran::NUMBER(units, 11);}}}
  else if(tens == 1){
      if(units == 1) {Ecran::NUMBER(hundreds, 8); Ecran::NUMBER(tens, 10); Ecran::NUMBER(units, 12);}
      else {Ecran::NUMBER(hundreds, 7); Ecran::NUMBER(tens, 9); Ecran::NUMBER(units, 11);}}
    else if(units == 1) {Ecran::NUMBER(hundreds, 7); Ecran::NUMBER(tens, 9); Ecran::NUMBER(units, 13);}
         else {Ecran::NUMBER(hundreds, 6); Ecran::NUMBER(tens, 8); Ecran::NUMBER(units, 12);}}

void Ecran::BATTERY(float x, float y) {//Permet d'afficher la tension des batterie
  if(x <= 44) {
    unsigned long currentMillis_B = millis();
    if (currentMillis_B - previousMillis_B >= interval) 
      {previousMillis_B = currentMillis_B;
      if (etat_B == 1) {etat_B = 0;
        lcd.setCursor(16,0); lcd.write(7);
        lcd.setCursor(17,0); lcd.print("VGB");
        lcd.setCursor(16,1); lcd.print("    ");} 
      else {etat_B = 1;
        lcd.setCursor(16,0); lcd.write(3);
        lcd.setCursor(17,0); lcd.print("VGB");
        lcd.setCursor(16,1); lcd.print(x, 1);}}}
  else {  
    lcd.setCursor(16,0); lcd.write(3);
    lcd.setCursor(17,0); lcd.print("VGB");
    lcd.setCursor(16,1); lcd.print(x, 1);}
  if(y <= 11) {
    unsigned long currentMillis_L = millis();
    if (currentMillis_L - previousMillis_L >= interval) 
      {previousMillis_L = currentMillis_L;
      if (etat_L == 1) {etat_L = 0;
        lcd.setCursor(16,2); lcd.write(7);
        lcd.setCursor(17,2); lcd.print("VPB");
        lcd.setCursor(16,3); lcd.print("    ");} 
      else {etat_L = 1;
        lcd.setCursor(16,2); lcd.write(3);
        lcd.setCursor(17,2); lcd.print("VPB");
        lcd.setCursor(16,3); lcd.print(y, 1);}}}
  else { 
    lcd.setCursor(16,2); lcd.write(3);
    lcd.setCursor(17,2); lcd.print("VPB");
    lcd.setCursor(16,3); lcd.print(y, 1);}}

void Ecran::PIT_LCD() {//Permet d'afficher une alerte PIT
  int x = 4;
  if(etat_clean == true) {CLEAN_LCD(); etat_clean = false;}

  //AFFICHAGE DE "P"
  lcd.setCursor(x,0); lcd.write(6);
  lcd.setCursor(x,1); lcd.write(6);
  lcd.setCursor(x,2); lcd.write(6);
  lcd.setCursor(x,3); lcd.write(6);
  lcd.setCursor((x+1),0); lcd.write(6);
  lcd.setCursor((x+1),2); lcd.write(6);
  lcd.setCursor((x+2),0); lcd.write(6);
  lcd.setCursor((x+2),1); lcd.write(6);
  lcd.setCursor((x+2),2); lcd.write(6);

  //AFFICHAGE DE "I"
  lcd.setCursor((x+4),0); lcd.write(6);
  lcd.setCursor((x+4),3); lcd.write(6);
  lcd.setCursor((x+5),0); lcd.write(6);  
  lcd.setCursor((x+5),1); lcd.write(6);
  lcd.setCursor((x+5),2); lcd.write(6);
  lcd.setCursor((x+5),3); lcd.write(6);
  lcd.setCursor((x+6),0); lcd.write(6);
  lcd.setCursor((x+6),3); lcd.write(6);

  //AFFICHAGE DE "T"
  lcd.setCursor((x+8),0); lcd.write(6);
  lcd.setCursor((x+9),0); lcd.write(6);  
  lcd.setCursor((x+9),1); lcd.write(6);
  lcd.setCursor((x+9),2); lcd.write(6);
  lcd.setCursor((x+9),3); lcd.write(6);
  lcd.setCursor((x+10),0); lcd.write(6);

  //AFFICHAGE DE "!"
  lcd.setCursor((x+12),0); lcd.write(6);  
  lcd.setCursor((x+12),1); lcd.write(6);
  lcd.setCursor((x+12),2); lcd.write(6);
  lcd.setCursor((x+12),3); lcd.write(4);}

void Ecran::refresh()
{
  if(etat_PIT) {PIT_LCD();} //Si on recoie alarme du stand (supervions) affichage du mot PIT sur l'écran
  else {
    Ecran::SPEEDCOUNTER(speed);                                  //Gestion affichage vitesse
    Ecran::TOPSPEED(speed);                                      //Gestion vitesse maximum
    Ecran::BATTERY(BV48, BV12);    //Gestion batterie
    Ecran::CHRONOMETER();                                        //Gestion chronomètre

    etat_clean = true; 

    //A utiliser pour phase de test
    
    speed++; 
    delay(200);
    

  }
}