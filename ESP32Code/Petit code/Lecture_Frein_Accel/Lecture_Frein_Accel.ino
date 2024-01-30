#include <Arduino.h>

#define FREIN 36
#define ACCEL 39

int Fr_Prcent = 0, Ac_Prcent = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(FREIN, INPUT);
    pinMode(ACCEL, INPUT);
}

void loop()
{
    Fr_Prcent = (int)((float)(((analogRead(FREIN) * 3.3) / 4095) / 3.3) * 100);
    Ac_Prcent = (int)((float)(((analogRead(ACCEL) * 3.3) / 4095) / 3.3) * 100);

    Serial.print("Frein : ");
    Serial.println(Fr_Prcent);
    Serial.print("Accel : ");
    Serial.println(Ac_Prcent);

    delay(500);
}