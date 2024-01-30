#include "module_lora.h"
#include <SoftwareSerial.h>


SoftwareSerial SoftSerial(17, 16);
unsigned char buffer[64];                  
int count=0;                                


const uint8_t dataPacketSize = sizeof(float) * 7 + sizeof(float) * 2; 
uint8_t dataPacket[dataPacketSize];

CModuleLoRa* pModuleLoRa = NULL;
float floatsToSend[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; 
float latitude = 48.4423344;
float longitude = 1.496218;

void setup() {
  SoftSerial.begin(9600);                 
  Serial.begin(9600); 
  delay(3000);
  Serial.println("*** Started ***");

  pModuleLoRa = CModuleLoRa::GetInstance();
  pModuleLoRa->init(16, 17);
  pModuleLoRa->setConfig();
  pModuleLoRa->getConfig();
  pModuleLoRa->getInfo();
  
  Serial.println("*** Setup done ***");
}

void loop() {
  for (int i = 0; i < 7; i++) {
    floatsToSend[i] += 1.0;
  }
  latitude = latitude + 0.00001;
  longitude = longitude + 0.00001;
  

  memcpy(dataPacket, floatsToSend, sizeof(float) * 7);
  memcpy(dataPacket + sizeof(float) * 7, &latitude, sizeof(float));
  memcpy(dataPacket + sizeof(float) * 7 + sizeof(float), &longitude, sizeof(float));


  pModuleLoRa->radioTX(dataPacket, dataPacketSize);
}



