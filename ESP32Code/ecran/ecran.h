// Ecran.h

#include "../CONFIG_H.h"
#include "../1Librairies/LiquidCrystal_I2C/LiquidCrystal_I2C.cpp"

#ifndef Ecran_h
#define Ecran_h

#include <Arduino.h>

#define BPD 33
#define BPS 32
#define BPR 5
#define TAILLE_TABLEAU_MAX 100


class Ecran
{
  public:
    Ecran(int I2C_SCL, int I2C_SDA);

    int I2C_SCL;
    int I2C_SDA;

    void begin();
    void refresh();
    void TEMPERATURE_MOTOR(float x);

    int speed = 0; //speed correspond à la vitesse du kart pour TOPSPEED et SPEEDCOUNTER
    float BV48 = 48, BV12 = 12;  //TBB et TSB correspond au tension des batteries pour BATTERY
    bool running; //CHRONOMETER
    // interrupt
    
    

    //Déclaration des variables utiles dans le programme
    bool etat_PIT = false, etat_clean; //PITLCD
    int hundreds, tens, units; //SPEEDCOUNTER
    float temp_moteur = 0.;
    float temp_bat1 = 0., temp_bat2 = 0., temp_bat3 = 0., temp_bat4 = 0.;
    int average_time, best_time, last_time = 0;
    int etat_menu = 1;
    bool affichage_chrono = true;
    static bool CPT_display, CPT_start, CPT_reset ,counter_start , counter_stop , counter_reset , counter_passage  ; // pour interruptions
    bool passage = true;
    bool force_start = false;

    // static void incrementDisplay();
    // static void incrementStart();
    // static void incrementReset();

  private:




int chrono[TAILLE_TABLEAU_MAX] = {0}; // Initialisation du tableau de valeurs
int tailleTableau = 0; // Taille actuelle du tableau



   



//Déclaration des variables utiles pour les fonctions
unsigned long startTime = 0; //CHRONOMETER
unsigned long elapsedTime = 0; ///CHRONOMETER
unsigned long previousMillis_B = 0, previousMillis_L = 0; //BATTERY
const long interval = 500; //BATTERY
int speed_max=0; //TOPSPEED
int etat_B = 1, etat_L = 1; //BATTERY
unsigned long previousMillis_GO = 0;  //ECRAN 3 2 1 GO


    


    LiquidCrystal_I2C lcd;

    void GO_GEII();
    void GO_LCD();
    void NUMBER(int x, int y);
    void CLEAN_COLUMN(int x);
    void CLEAN_LCD();
    void CHRONOMETER(bool x);
    void TOPSPEED(int x);
    void SPEEDCOUNTER(int x);
    void TEMPERATURE_BATTERY(float w,float x, float y, float z);
    void BATTERY(float x, float y);
    void PIT_LCD();
    void ajouterNouvelleValeur(int valeur);
    void trier(int tableau[], int taille);
    void afficherValeurs(int tableau[], int taille);
    float calculerMoyenne(int tableau[], int taille);
    int trouverPlusPetite(int tableau[], int taille);
    void CLASSEMENT(float x);
    void CHRONO_AVERAGE();
    void CHRONO_BEST();
    void MENU_1(bool display_chrono, int speed, float x, float y);
    void MENU_2(bool display_chrono, int speed, float w, float x, float y, float z);
    void MENU_3(bool display_chrono, int speed);
    void MENU_CLASSEMENT();
 
    // +
};


//Déclaration des caractères spréciaux
byte Eclair[] = {0x02, 0x06, 0x0C, 0x1F, 0x06, 0x0C, 0x08, 0x00};
byte Chrono[] = {0x0E, 0x04, 0x0E, 0x13, 0x15, 0x11, 0x0E, 0x00};
byte BOT[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F};
byte TOP[] = {0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00};
byte FULL[] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
byte BATTL[] = {0x0E, 0x1B, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x00};
byte BATTF[] = {0x0E, 0x1B, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};
byte SUN[] = {0x04, 0x11, 0x0E, 0x1F, 0x0E, 0x11, 0x04, 0x00};
char mid = 0xFD, empty = 0x20, degre = 0xB0;

#endif





