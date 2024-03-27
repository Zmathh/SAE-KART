#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "esp32-hal-gpio.h"












void NUMBER(int x, int y) {//Permet l'affichage des chiffres 0 à 9
 
void CLEAN_COLUMN(int x) {//Permet de nettoyer une colonne pour optimiser l'affichage de la vitesse
  

void CLEAN_LCD() {//Permet de nettoyer l'ensemble de l'écran (optimisation : lcd.clear)
  
  

void CHRONOMETER(bool x) {//Affichage et gestion du chronomètre (pour l'instant avec le moniteur série)


void TOPSPEED(int x) {//Permet d'afficher la vitesse max atteinte
  

void SPEEDCOUNTER(int x) {//Permet la gestion de l'affichage de la vitesse (fonctionne avec la fonction NUMBER)
  

void BATTERY(float x, float y) {//Permet d'afficher la tension des batterie
  



void PIT_LCD() {//Permet d'afficher une alerte PIT
 


void ajouterNouvelleValeur(int valeur) {
  if (tailleTableau < TAILLE_TABLEAU_MAX) {chrono[tailleTableau] = valeur; tailleTableau++;} 
  else {Serial.println("Le tableau est plein, impossible d'ajouter une nouvelle valeur.");}}

void trier(int tableau[], int taille) {
  for (int i = 0; i < taille - 1; i++) {
    for (int j = 0; j < taille - i - 1; j++) {
      if (tableau[j] > tableau[j + 1]) {int temp = tableau[j]; tableau[j] = tableau[j + 1]; tableau[j + 1] = temp;}}}}

void afficherValeurs(int tableau[], int taille) {
  Serial.println("Valeurs triées :");
  for (int i = 0; i < taille; i++) {Serial.print(tableau[i]); Serial.print(" ");} Serial.println();}

float calculerMoyenne(int tableau[], int taille) {
  float somme = 0;
  for (int i = 0; i < taille; i++) {somme += tableau[i];}
  return somme / taille;}

int trouverPlusPetite(int tableau[], int taille) {
  int min = tableau[0];
  for (int i = 1; i < taille; i++) {if (tableau[i] < min) {min = tableau[i];}}
  return min;}

void CLASSEMENT(float x){
  ajouterNouvelleValeur(x);
  trier(chrono, tailleTableau);
  afficherValeurs(chrono, tailleTableau);}

void CHRONO_AVERAGE() {
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

void CHRONO_BEST() {
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

void MENU_1(bool display_chrono, float speed, float x, float y, float z) {
  CHRONOMETER(display_chrono);
  SPEEDCOUNTER(speed);
  BATTERY(x, y);
  TEMPERATURE_MOTOR(z);}

void MENU_2(bool display_chrono, float speed, float w, float x, float y, float z) {
  CHRONOMETER(display_chrono);
  SPEEDCOUNTER(speed);
  TEMPERATURE_BATTERY(w, x, y, z);}

void MENU_3(bool display_chrono, float speed) {
  CHRONOMETER(display_chrono);
  if (last_time > 0) {CLASSEMENT(last_time); last_time = 0;}
  SPEEDCOUNTER(speed);
  TOPSPEED(speed);
  CHRONO_AVERAGE();
  CHRONO_BEST();}

void MENU_CLASSEMENT() {
  lcd.setCursor(4, 0); lcd.print("Classement");
  lcd.setCursor(5, 1); lcd.print("1- "); lcd.print(chrono[0]);
  lcd.setCursor(5, 2); lcd.print("2- "); lcd.print(chrono[1]);
  lcd.setCursor(5, 3); lcd.print("3- "); lcd.print(chrono[2]);}

void loop() {
  if (CPT) {etat_menu++; CLEAN_LCD(); CPT = false;}
  if (etat_menu > 3) {etat_menu = 1;}
  if (etat_menu == 1) {MENU_1(true, speed, BV48, BV12, temp_moteur);}
  if (etat_menu == 2) {MENU_2(false, speed, temp_bat1, temp_bat2, temp_bat3, temp_bat4);}
  if (etat_menu == 3) {MENU_3(false, speed);}
}

void incrementDisplay() {CPT = true; Serial.println("PASSAGE DISPLAY");}
void incrementStart() {
  Serial.println("PASSAGE START/STOP"); 
  counter_passage = true;
  counter_start = true;
  //if (counter_start) {counter_stop = true;}
  //if (counter_stop) {counter_start = true;}
}
void incrementReset() {Serial.println("PASSAGE RESET"); counter_reset = true; counter_passage = true;}