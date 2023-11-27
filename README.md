# SAE-KART LoRa
![Kart](images/Kart.jpg)



Simple KiCad design for an Arduino compatible RN2483 (or RN2903) LoRaWA suited for our Project.

Fork of the original [jpmeyers/RN2483shield](https://github.com/jpmeijers/RN2483shield).

![top layout](module_LoRa_Kicad/images/top_rev1.png)
***Top board view***

![bottom layout](module_LoRa_Kicad/images/bottom_rev1.png)
***Bottom board view***


Adjusted to:

 * ignore the 433MHz antenna trace (868MHz only),
 

## Required Parts for PCB

 * 3× 10k resistors,
 * 1× SMA 868MHz antenna,
 * 1x RN2483 (or RN2903)

## Setting up

WIP
-debug possible

## Schematic

![Schematic](module_LoRa_Kicad/images/Schematic.png)
***Schematic***

![PCB](module_LoRa_Kicad/images/PCB.png)
***PCB***


## Solidworks Case
![Solidworks](SAE-KART/solidworks/Solidworks_view.png)
***Solidworks view***

## RF Impedance Analyser Results

![First_vers](SAE-KART/images/First_vers.jpg)
First Version was a little off the mark because we didn't followed precisely datasheet from the [LoRa module](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/RN2483-Low-Power-Long-Range-LoRa-Technology-Transceiver-Module-DS50002346F.pdf) where P.12
![Datasheet](SAE-KART/images/Datasheet.png)
***[Datasheet P.12](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/RN2483-Low-Power-Long-Range-LoRa-Technology-Transceiver-Module-DS50002346F.pdf)***

![Second_vers](SAE-KART/images/Second_vers.jpg)
After 


## Final result

![Final result](SAE-KART/solidworks/images/final_result.png)
***Final result***

