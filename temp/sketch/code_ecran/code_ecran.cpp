#line 1 "C:\\Users\\Arno\\Desktop\\SAE-KART\\ESP32Code\\code_ecran\\code_ecran.cpp"
#include <Wire.h> 
#include "..\1Librairies\LiquidCrystal_I2C\LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27,20,4);

//Déclaration des caractères spréciaux
byte Eclair[] = {0x02, 0x06, 0x0C, 0x1F, 0x06, 0x0C, 0x08, 0x00};
byte Chrono[] = {0x0E, 0x04, 0x0E, 0x13, 0x15, 0x11, 0x0E, 0x00};
byte BOT[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F};
byte TOP[] = {0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00};
byte FULL[] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
byte BATTL[] = {0x0E, 0x1B, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x00};
byte BATTF[] = {0x0E, 0x1B, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
char mid = 0xFD, empty = 0x20;

//Déclaration des variables utiles pour les fonctions
bool running = false; //CHRONOMETER
unsigned long startTime = 0; //CHRONOMETER
unsigned long elapsedTime = 0; ///CHRONOMETER
unsigned long previousMillis_B = 0, previousMillis_L = 0; //BATTERY
const long interval = 500; //BATTERY
int speed_max; //TOPSPEED
int etat_B = 1, etat_L = 1; //BATTERY

//Déclaration des variables utiles dans le programme
bool etat_PIT = false, etat_clean; //PITLCD
int hundreds, tens, units; //SPEEDCOUNTER
int speed = 0; //speed correspond à la vitesse du kart pour TOPSPEED et SPEEDCOUNTER
float tension_big_battery = 48, tension_small_battery = 12; //TBB et TSB correspond au tension des batteries pour BATTERY



void NUMBER(int x, int y) {//Permet l'affichage des chiffres 0 à 9
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

void CLEAN_COLUMN(int x) {//Permet de nettoyer une colonne pour optimiser l'affichage de la vitesse
  lcd.setCursor(x,0); lcd.write(empty);
  lcd.setCursor(x,1); lcd.write(empty);
  lcd.setCursor(x,2); lcd.write(empty);}

void CLEAN_LCD() {//Permet de nettoyer l'ensemble de l'écran (optimisation : lcd.clear)
  for(int i =0; i<=19; i++) {
    lcd.setCursor(i,0); lcd.write(empty);
    lcd.setCursor(i,1); lcd.write(empty);
    lcd.setCursor(i,2); lcd.write(empty);
    lcd.setCursor(i,3); lcd.write(empty);}}
  

void CHRONOMETER() {//Affichage et gestion du chronomètre (pour l'instant avec le moniteur série)
  lcd.setCursor(2,0); lcd.write(1);
  lcd.setCursor(0,1); lcd.print("00:00");
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');;
    if (command == "start") {
      if (!running) {startTime = millis() - elapsedTime; running = true;}} 
      else if (command == "stop") {
      if (running) {elapsedTime = millis() - startTime; running = false;}}
      else if (command == "reset") {elapsedTime = 0; running = false;}}
  if (running) {unsigned long currentTime = millis(); elapsedTime = currentTime - startTime;}
  int minutes = elapsedTime / 60000;
  int seconds = (elapsedTime % 60000) / 1000;
  lcd.setCursor(0,1);
  if(minutes < 10) {lcd.print("0"); lcd.print(minutes);}
  else {lcd.print(minutes);}
  lcd.print(":");
  if(seconds < 10) {lcd.print("0"); lcd.print(seconds);}
  else {lcd.print(seconds);}}

void TOPSPEED(int x) {//Permet d'afficher la vitesse max atteinte
  lcd.setCursor(2,2); lcd.write(0);
  if(x > speed_max) {speed_max = x;}
  if(speed_max >= 100) {lcd.setCursor(1,3); lcd.print(speed_max);}
  else if(speed_max < 10) 
          if(speed_max == 0) {lcd.setCursor(1,3); lcd.print("N-D");}
          else {lcd.setCursor(1,3); lcd.print("00"); lcd.setCursor(3,3); lcd.print(speed_max);}
       else {lcd.setCursor(1,3); lcd.print("0"); lcd.setCursor(2,3); lcd.print(speed_max);}} 

void SPEEDCOUNTER(int x) {//Permet la gestion de l'affichage de la vitesse (fonctionne avec la fonction NUMBER)
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
         else {NUMBER(hundreds, 6); NUMBER(tens, 8); NUMBER(units, 12);}}

void BATTERY(float x, float y) {//Permet d'afficher la tension des batterie
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

void PIT_LCD() {//Permet d'afficher une alerte PIT
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



    