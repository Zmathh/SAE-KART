#include "module_lora.h"
#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(8, 9);
unsigned char buffer[64];                   // buffer array for data receive over serial port
int count=0;                                // counter for buffer array


const uint8_t dataPacketSize = sizeof(float) * 7 + sizeof(float) * 2; // Total size for 7 floats and 2 additional floats for latitude and longitude
uint8_t dataPacket[dataPacketSize]; // Array to store the data to be sent

CModuleLoRa* pModuleLoRa = NULL;
float floatsToSend[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; // Replace these with your actual float values
float latitude = 48.4423344;
float longitude = 1.496218;

void setup() {
  SoftSerial.begin(9600);                 // the SoftSerial baud rate
  Serial.begin(9600); 
  delay(3000);
  //while(!Serial);
  Serial.println("*** Started ***");

  pModuleLoRa = CModuleLoRa::GetInstance();
  pModuleLoRa->init(44, 43);
  pModuleLoRa->setConfig();
  pModuleLoRa->getConfig();
  pModuleLoRa->getInfo();
  
  Serial.println("*** Setup done ***");
}

void loop() {
  for (int i = 0; i < 7; i++) {
    floatsToSend[i] += 1.0;
  }
  // Prepare the data to be sent
  latitude = latitude + 0.00001;
  longitude = longitude + 0.00001;
  
  // Copy the float values and latitude/longitude into the dataPacket array
  memcpy(dataPacket, floatsToSend, sizeof(float) * 7);
  memcpy(dataPacket + sizeof(float) * 7, &latitude, sizeof(float));
  memcpy(dataPacket + sizeof(float) * 7 + sizeof(float), &longitude, sizeof(float));

  // Send the data
  pModuleLoRa->radioTX(dataPacket, dataPacketSize);
}



