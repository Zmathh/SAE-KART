
#include <Wire.h> 
#include "ecran.h"


//TwoWire I2Cone = TwoWire(0);
// LiquidCrystal_I2C lcd(0x27,20,4);


bool Ecran::CPT_display = false; bool Ecran::CPT_start = false; bool Ecran::CPT_reset = false;
bool Ecran::counter_passage = false;
bool Ecran::counter_reset = false;
bool Ecran::counter_start = false;
bool Ecran::counter_stop = true;

Ecran::Ecran(int I2C_SCL, int I2C_SDA) : lcd(0x27, 20,4) {
  this->I2C_SCL = I2C_SCL;
  this->I2C_SDA = I2C_SDA;
}

void Ecran::begin() {
  lcd.begin(I2C_SDA, I2C_SCL); lcd.backlight();
  //Serial.begin(9600);
  //I2Cone.begin(SDA, SCL,400000);

  //Interruption & Bouton
  // pinMode(BPD, INPUT);
  //pinMode(BPS, INPUT);
  //pinMode(BPR, INPUT);
  // attachInterrupt(BPD, incrementDisplay, FALLING);
  // attachInterrupt(BPS, incrementStart, FALLING);
  // attachInterrupt(BPR, incrementReset, FALLING);

  //Création des caractères spéciaux
  lcd.createChar(0, Eclair); lcd.createChar(1, Chrono); lcd.createChar(2, SUN);
  lcd.createChar(4, BOT);    lcd.createChar(5, TOP);    lcd.createChar(6, FULL);
  lcd.createChar(7, BATTL);  lcd.createChar(3, BATTF);

  //Affichage GEII
  GO_GEII();
  unsigned long currentMillis = millis();
  while (currentMillis - previousMillis_GO <= 5000) {currentMillis = millis();}
  previousMillis_GO = currentMillis;
  CLEAN_LCD();
}
void Ecran::GO_GEII(){
  //AFFICHAGE DE "G"
  lcd.setCursor(3, 0); lcd.write(6);
  lcd.setCursor(3, 1); lcd.write(6);
  lcd.setCursor(3, 2); lcd.write(6);
  lcd.setCursor(3, 3); lcd.write(6);
  lcd.setCursor(4, 0); lcd.write(5);
  lcd.setCursor(4, 3); lcd.write(4);
  lcd.setCursor(5, 0); lcd.write(5);
  lcd.setCursor(5, 2); lcd.write(5);
  lcd.setCursor(5, 3); lcd.write(4);
  lcd.setCursor(6, 0); lcd.write(5);
  lcd.setCursor(6, 2); lcd.write(6);
  lcd.setCursor(6, 3); lcd.write(6);

  //AFFICHAGE DE "E"
  lcd.setCursor(8, 0); lcd.write(6);
  lcd.setCursor(8, 1); lcd.write(6);
  lcd.setCursor(8, 2); lcd.write(6);
  lcd.setCursor(8, 3); lcd.write(6);
  lcd.setCursor(9, 0); lcd.write(5);
  lcd.setCursor(9, 1); lcd.write(4);
  lcd.setCursor(9, 2); lcd.write(5);
  lcd.setCursor(9, 3); lcd.write(4);
  lcd.setCursor(10, 0); lcd.write(5);
  lcd.setCursor(10, 1); lcd.write(4);
  lcd.setCursor(10, 2); lcd.write(5);
  lcd.setCursor(10, 3); lcd.write(4);
  lcd.setCursor(11, 0); lcd.write(5);
  lcd.setCursor(11, 3); lcd.write(4);

  //AFFICHAGE DE "I"
  lcd.setCursor(13, 0); lcd.write(6);
  lcd.setCursor(13, 1); lcd.write(6);
  lcd.setCursor(13, 2); lcd.write(6);
  lcd.setCursor(13, 3); lcd.write(6);
  lcd.setCursor(15, 0); lcd.write(6);
  lcd.setCursor(15, 1); lcd.write(6);
  lcd.setCursor(15, 2); lcd.write(6);
  lcd.setCursor(15, 3); lcd.write(6);
  }

  void Ecran::GO_LCD(){
  int x = 4;
  //unsigned long currentMillis = millis();

  if(etat_clean == true) {CLEAN_LCD(); etat_clean = false;}

  //AFFICHAGE DE "3"
  lcd.setCursor(x+4, 0); lcd.write(5);
  lcd.setCursor(x+4, 3); lcd.write(4);
  lcd.setCursor(x+5, 0); lcd.write(5);
  lcd.setCursor(x+5, 1); lcd.write(4);
  lcd.setCursor(x+5, 2); lcd.write(5);
  lcd.setCursor(x+5, 3); lcd.write(4);
  lcd.setCursor(x+6, 0); lcd.write(5);
  lcd.setCursor(x+6, 1); lcd.write(4);
  lcd.setCursor(x+6, 2); lcd.write(5);
  lcd.setCursor(x+6, 3); lcd.write(4);
  lcd.setCursor(x+7, 0); lcd.write(6);
  lcd.setCursor(x+7, 1); lcd.write(6);
  lcd.setCursor(x+7, 2); lcd.write(6);
  lcd.setCursor(x+7, 3); lcd.write(6);
  unsigned long currentMillis = millis();
  while (currentMillis - previousMillis_GO <= 1000) {currentMillis = millis();}
  previousMillis_GO = currentMillis;
  CLEAN_LCD();

  //AFFICHAGE DE "2"
  lcd.setCursor(x+4, 0); lcd.write(5);
  lcd.setCursor(x+4, 1); lcd.write(4);
  lcd.setCursor(x+4, 2); lcd.write(6);
  lcd.setCursor(x+4, 3); lcd.write(6);
  lcd.setCursor(x+5, 0); lcd.write(5);
  lcd.setCursor(x+5, 1); lcd.write(4);
  lcd.setCursor(x+5, 2); lcd.write(5);
  lcd.setCursor(x+5, 3); lcd.write(4);
  lcd.setCursor(x+6, 0); lcd.write(5);
  lcd.setCursor(x+6, 1); lcd.write(4);
  lcd.setCursor(x+6, 2); lcd.write(5);
  lcd.setCursor(x+6, 3); lcd.write(4);
  lcd.setCursor(x+7, 0); lcd.write(6);
  lcd.setCursor(x+7, 1); lcd.write(6);
  lcd.setCursor(x+7, 2); lcd.write(5);
  lcd.setCursor(x+7, 3); lcd.write(4);
  currentMillis = millis();
  while (currentMillis - previousMillis_GO <= 1000) {currentMillis = millis();}
  previousMillis_GO = currentMillis;
  CLEAN_LCD();

  //AFFICHAGE DE "1"
  lcd.setCursor(x+5, 0); lcd.write(4);
  lcd.setCursor(x+5, 3); lcd.write(4);
  lcd.setCursor(x+6, 0); lcd.write(6);
  lcd.setCursor(x+6, 1); lcd.write(6);
  lcd.setCursor(x+6, 2); lcd.write(6);
  lcd.setCursor(x+6, 3); lcd.write(6);
  lcd.setCursor(x+7, 3); lcd.write(4);
  currentMillis = millis();
  while (currentMillis - previousMillis_GO <= 1000) {currentMillis = millis();}
  previousMillis_GO = currentMillis;
  CLEAN_LCD();

  //AFFICHAGE DE "G"
  lcd.setCursor(x, 0); lcd.write(6);
  lcd.setCursor(x, 1); lcd.write(6);
  lcd.setCursor(x, 2); lcd.write(6);
  lcd.setCursor(x, 3); lcd.write(6);
  lcd.setCursor(x+1, 0); lcd.write(5);
  lcd.setCursor(x+1, 3); lcd.write(4);
  lcd.setCursor(x+2, 0); lcd.write(5);
  lcd.setCursor(x+2, 2); lcd.write(5);
  lcd.setCursor(x+2, 3); lcd.write(4);
  lcd.setCursor(x+3, 0); lcd.write(5);
  lcd.setCursor(x+3, 2); lcd.write(6);
  lcd.setCursor(x+3, 3); lcd.write(6);

  //AFFICHAGE DE "O"
  lcd.setCursor(x+5, 0); lcd.write(6);
  lcd.setCursor(x+5, 1); lcd.write(6);
  lcd.setCursor(x+5, 2); lcd.write(6);
  lcd.setCursor(x+5, 3); lcd.write(6);
  lcd.setCursor(x+6, 0); lcd.write(5);
  lcd.setCursor(x+6, 3); lcd.write(4);
  lcd.setCursor(x+7, 0); lcd.write(5);
  lcd.setCursor(x+7, 3); lcd.write(4);
  lcd.setCursor(x+8, 0); lcd.write(6);
  lcd.setCursor(x+8, 1); lcd.write(6);
  lcd.setCursor(x+8, 2); lcd.write(6);
  lcd.setCursor(x+8, 3); lcd.write(6);

  //AFFICHAGE DE "!"
  lcd.setCursor(x+10, 0); lcd.write(6);
  lcd.setCursor(x+10, 1); lcd.write(6);
  lcd.setCursor(x+10, 2); lcd.write(6);
  lcd.setCursor(x+10, 3); lcd.write(4);
  lcd.setCursor(x+12, 0); lcd.write(6);
  lcd.setCursor(x+12, 1); lcd.write(6);
  lcd.setCursor(x+12, 2); lcd.write(6);
  lcd.setCursor(x+12, 3); lcd.write(4);
  currentMillis = millis();
  while (currentMillis - previousMillis_GO <= 1000) {currentMillis = millis();}
  previousMillis_GO = currentMillis;
  CLEAN_LCD();
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
  

void Ecran::CHRONOMETER(bool x) {
  if (CPT_start && counter_stop && (!counter_start)) {counter_start = true; CPT_start = false;}
  if (CPT_start && (!counter_stop) && counter_start) {counter_stop = true; CPT_start = false;}
  if (CPT_reset) {counter_reset = true; CPT_reset = false;}
  ///////////////////////////////////////////////Définition du START/STOP/RESET  /////////////////////////////////////////////////////////////////
    if ((Serial.available() > 0) or (force_start) or (counter_passage)) {
    String command = Serial.readStringUntil('\n');
    if ((counter_start) or (force_start) or (command == "start")) {
      if (!running) {startTime = millis() - elapsedTime; running = true; force_start = false; counter_stop = false;}} 
    if ((counter_stop) or (command == "stop")) {
      if (running) {last_time = elapsedTime; elapsedTime = millis() - startTime; running = false; counter_start = false;}}
    if ((counter_reset) or (command == "reset")) {
      if (running) {last_time = elapsedTime; force_start = true;} elapsedTime = 0; running = false; counter_reset = false;}}
   /////////////////////////////////////////////// /////////////////////////////////////////////// ///////////////////////////////////////////////
  if (running) {unsigned long currentTime = millis(); elapsedTime = currentTime - startTime;}
  int minutes = elapsedTime / 60000;
  int seconds = (elapsedTime % 60000) / 1000;
  if(x) {
    lcd.setCursor(2,0); lcd.write(1);
    if ((seconds == 0) and (minutes == 0)) {lcd.setCursor(0,1); } 
    lcd.setCursor(0,1);
    if(minutes < 10) {lcd.print("0"); lcd.print(minutes);}
    else {lcd.print(minutes);}
    lcd.print(":");
    if(seconds < 10) {lcd.print("0"); lcd.print(seconds);}
    else {lcd.print(seconds);}}
  counter_passage = false;}

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
  lcd.setCursor(8,3); lcd.print("km/hr");

  //A utiliser en phase de test
  /*
  if(hundreds == 1) {x += 100;} //A utiliser quand phase de test
  if(x >= 150) {etat_PIT = true;}
  */

  if(hundreds == 0) {
    CLEAN_COLUMN(6); CLEAN_COLUMN(14); //Clean colonne 6 et 14 qyand on passe de 100 ves <100
    if(tens <= 1){
      if(tens == 0) {
        if(units == 1) {CLEAN_COLUMN(7); CLEAN_COLUMN(8); CLEAN_COLUMN(12); CLEAN_COLUMN(13); NUMBER(units, 10);} 
        else {CLEAN_COLUMN(7); CLEAN_COLUMN(13); NUMBER(units, 9);}}
      if(tens == 1) {
        if(units == 1) {CLEAN_COLUMN(7); CLEAN_COLUMN(13); NUMBER(units, 11); NUMBER(tens, 9);}
        else {NUMBER(units, 10); NUMBER(tens, 8);}}}
    if(tens >= 2) {
      if(units == 1) {NUMBER(tens, 8); NUMBER(units, 12);} 
      else {NUMBER(tens, 7); NUMBER(units, 11);}}}
  else if(tens == 1){
      if(units == 1) {NUMBER(hundreds, 8); NUMBER(tens, 10); NUMBER(units, 12);}
      else {NUMBER(hundreds, 7); NUMBER(tens, 9); NUMBER(units, 11);}}
    else if(units == 1) {NUMBER(hundreds, 7); NUMBER(tens, 9); NUMBER(units, 13);}
         else {NUMBER(hundreds, 6); NUMBER(tens, 8); NUMBER(units, 12);}
}

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

void Ecran::TEMPERATURE_BATTERY(float w,float x, float y, float z) {//Permet l'affichage des température batteries
  //Température Haut Gauche
  lcd.setCursor(2,0); lcd.write(2);
  //lcd.setCursor(0,1); lcd.print("0");
  lcd.setCursor(1,1); lcd.print(w, 0);
  lcd.setCursor(3,1); lcd.print(degre);
  lcd.setCursor(4,1); lcd.print("C");

  //Température Bas Gauche
  lcd.setCursor(2,2); lcd.write(2);
  //lcd.setCursor(0,3); lcd.print("0");
  lcd.setCursor(1,3); lcd.print(x, 0);
  lcd.setCursor(3,3); lcd.print(degre);
  lcd.setCursor(4,3); lcd.print("C");
  
  //Température Haut Droite
  lcd.setCursor(17,0); lcd.write(2);
  //lcd.setCursor(15,1); lcd.print("0");
  lcd.setCursor(16,1); lcd.print(y, 0);
  lcd.setCursor(18,1); lcd.print(degre);
  lcd.setCursor(19,1); lcd.print("C");

  //Température Bas Droite
  lcd.setCursor(17,2); lcd.write(2);
  //lcd.setCursor(15,3); lcd.print("0");
  lcd.setCursor(16,3); lcd.print(z, 0);
  lcd.setCursor(18,3); lcd.print(degre);
  lcd.setCursor(19,3); lcd.print("C");}

void Ecran::TEMPERATURE_MOTOR(float x) {//Permet l'affichage de la température moteur
  lcd.setCursor(2,2); lcd.write(2);
  //lcd.setCursor(0,3); lcd.print("0");
  lcd.setCursor(1,3); lcd.print(x, 0);
  lcd.setCursor(3,3); lcd.print(degre);
  lcd.setCursor(4,3); lcd.print("C");
  }

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

void Ecran::ajouterNouvelleValeur(int valeur) {
  if (tailleTableau < TAILLE_TABLEAU_MAX) {chrono[tailleTableau] = valeur; tailleTableau++;} 
  else {Serial.println("Le tableau est plein, impossible d'ajouter une nouvelle valeur.");}}

void Ecran::trier(int tableau[], int taille) {
  for (int i = 0; i < taille - 1; i++) {
    for (int j = 0; j < taille - i - 1; j++) {
      if (tableau[j] > tableau[j + 1]) {int temp = tableau[j]; tableau[j] = tableau[j + 1]; tableau[j + 1] = temp;}}}}

void Ecran::afficherValeurs(int tableau[], int taille) {
  Serial.println("Valeurs triées :");
  for (int i = 0; i < taille; i++) {Serial.print(tableau[i]); Serial.print(" ");} Serial.println();}

float Ecran::calculerMoyenne(int tableau[], int taille) {
  float somme = 0;
  for (int i = 0; i < taille; i++) {somme += tableau[i];}
  return somme / taille;}

int Ecran::trouverPlusPetite(int tableau[], int taille) {
  int min = tableau[0];
  for (int i = 1; i < taille; i++) {if (tableau[i] < min) {min = tableau[i];}}
  return min;}

void Ecran::CLASSEMENT(float x){
  ajouterNouvelleValeur(x);
  trier(chrono, tailleTableau);
  afficherValeurs(chrono, tailleTableau);}

void Ecran::CHRONO_AVERAGE() {
  average_time = calculerMoyenne(chrono, tailleTableau);
  int minutes = average_time / 60000;
  int seconds = (average_time % 60000) / 1000;
  //Serial.print("Moyenne : ");
  //Serial.println(average_time);
  lcd.setCursor(16,0); lcd.write(1);
  lcd.setCursor(17,0); lcd.print("AT");
  lcd.setCursor(15,1);
  //if((seconds == 0) and (minutes == 0)) {lcd.print("00:00");}
  if(minutes < 10) {lcd.print("0"); lcd.print(minutes);}
  else {lcd.print(minutes);}
  lcd.print(":");
  if(seconds < 10) {lcd.print("0"); lcd.print(seconds);}
  else {lcd.print(seconds);}}

void Ecran::CHRONO_BEST() {
  best_time = trouverPlusPetite(chrono, tailleTableau);
  int minutes = best_time / 60000;
  int seconds = (best_time % 60000) / 1000;
  Serial.print("Meilleur temps : ");
  Serial.println(best_time);
  lcd.setCursor(1,0); lcd.write(1);
  lcd.setCursor(2,0); lcd.print("BT");
  lcd.setCursor(0,1);
  //if((seconds == 0) and (minutes == 0)) {lcd.print("00:00");}
  if(minutes < 10) {lcd.print("0"); lcd.print(minutes);}
  else {lcd.print(minutes);}
  lcd.print(":");
  if(seconds < 10) {lcd.print("0"); lcd.print(seconds);}
  else {lcd.print(seconds);}}

void Ecran::MENU_1(bool display_chrono, float speed, float x, float y, float z) {
  CHRONOMETER(display_chrono);
  SPEEDCOUNTER(speed);
  BATTERY(x, y);
  TEMPERATURE_MOTOR(z);}

void Ecran::MENU_2(bool display_chrono, float speed, float w, float x, float y, float z) {
  CHRONOMETER(display_chrono);
  SPEEDCOUNTER(speed);
  TEMPERATURE_BATTERY(w, x, y, z);}

void Ecran::MENU_3(bool display_chrono, float speed) {
  CHRONOMETER(display_chrono);
  if (last_time > 0) {CLASSEMENT(last_time); last_time = 0;}
  SPEEDCOUNTER(speed);
  TOPSPEED(speed);
  CHRONO_AVERAGE();
  CHRONO_BEST();}

void Ecran::MENU_CLASSEMENT() {
  lcd.setCursor(4, 0); lcd.print("Classement");
  lcd.setCursor(5, 1); lcd.print("1- "); lcd.print(chrono[0]);
  lcd.setCursor(5, 2); lcd.print("2- "); lcd.print(chrono[1]);
  lcd.setCursor(5, 3); lcd.print("3- "); lcd.print(chrono[2]);}

void Ecran::refresh() {
  if (CPT_display) {etat_menu++; CLEAN_LCD(); CPT_display = false;}
  if (etat_menu > 3) {etat_menu = 1;}
  if (etat_menu == 1) {MENU_1(true, speed, BV48, BV12, temp_moteur);}
  if (etat_menu == 2) {MENU_2(false, speed, temp_bat1, temp_bat2, temp_bat3, temp_bat4);}
  if (etat_menu == 3) {MENU_3(false, speed);}
}

// void Ecran::incrementDisplay() {Ecran::CPT = true; Serial.println("PASSAGE DISPLAY");}
// void Ecran::incrementStart() {
//   Serial.println("PASSAGE START/STOP"); 
//   Ecran::counter_passage = true;
//   Ecran::counter_start = true;
//   //if (counter_start) {counter_stop = true;}
//   //if (counter_stop) {counter_start = true;}
// }
// void Ecran::incrementReset() {Serial.println("PASSAGE RESET"); Ecran::counter_reset = true; Ecran::counter_passage = true;}