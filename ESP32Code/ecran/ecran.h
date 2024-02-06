// Ecran.h

#include "../CONFIG_H.h"
#include "../1Librairies/LiquidCrystal_I2C/LiquidCrystal_I2C.cpp"

#ifndef Ecran_h
#define Ecran_h

#include <Arduino.h>



class Ecran
{
  public:
    Ecran(int I2C_SCL, int i2C_SDA);

    int I2C_SCL;
    int I2C_SDA;

    void begin();
    void refresh();

    int speed; //speed correspond à la vitesse du kart pour TOPSPEED et SPEEDCOUNTER
    float BV48, BV12 ; //TBB et TSB correspond au tension des batteries pour BATTERY
    bool running; //CHRONOMETER

    

  private:




    char mid = 0xFD;
    char empty = 0x20;
    
    unsigned long startTime = 0; //CHRONOMETER
    unsigned long elapsedTime = 0; ///CHRONOMETER
    unsigned long previousMillis_B = 0, previousMillis_L = 0; //BATTERY
    const long interval = 500; //BATTERY
    int speed_max; //TOPSPEED
    int etat_B = 1, etat_L = 1; //BATTERY

    //Déclaration des variables utiles dans le programme
    bool etat_PIT = false, etat_clean; //PITLCD
    int hundreds, tens, units; //SPEEDCOUNTER
    


    LiquidCrystal_I2C lcd;

    void NUMBER(int x, int y);
    void CLEAN_COLUMN(int x);
    void CLEAN_LCD();
    void CHRONOMETER();
    void TOPSPEED(int x);
    void SPEEDCOUNTER(int x);
    void BATTERY(float x, float y);
    void PIT_LCD();

    // +
};


    // Création des caractères spéciaux
    byte Eclair[] = {0x02, 0x06, 0x0C, 0x1F, 0x06, 0x0C, 0x08, 0x00};
    byte Chrono[] = {0x0E, 0x04, 0x0E, 0x13, 0x15, 0x11, 0x0E, 0x00};
    byte BOT[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F};
    byte TOP[] = {0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00};
    byte FULL[] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
    byte BATTL[] = {0x0E, 0x1B, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x00};
    byte BATTF[] = {0x0E, 0x1B, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00};

#endif