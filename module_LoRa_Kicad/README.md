# RN2483shield

KiCad design for an Arduino compatible RN2483 (or RN2903) LoRaWAN shield.

Fork of the original [jpmeyers/RN2483shield](https://github.com/jpmeijers/RN2483shield).

![top layout](images/top_rev1.png)
***Top board view***

Adjusted to:

 * use the Microchip specified RF trace geometry to maintain R&TTE (CE) and FCC testing compliance for the radio module (datasheet pg. 12),
 * ignore the 433MHz antenna trace (868MHz only),
 * use solder jumper connections for Serial UART connection,
 * normally connected jumpers for default connections:
   * Serial D3 Tx → Radio Serial Rx,
   * Serial D2 Rx → Radio Serial Tx,
 * Mosfet level converters on the UART connection to allow 5V→3.3V signal conversion,
 * Breakout of all GPIO pins on the radio (GPIO 0–13),
 * edge mounted SMA connetion for antenna.

![bottom layout](images/bottom_rev1.png)
***Bottom board view***

## Required Parts

 * 1× Shield PCB,
 * 2× BSS138 SOT-23 N-channel MOSFET,
 * 5× 0603 10k resistors,
 * 1× SMA female edge jack,
 * 1× SMA 868MHz antenna,
 * 1× 1x10 stacking thru-headers,
 * 2× 1x8 stacking thru-headers,
 * 1× 1x6 stacking thru-headers

## Setting the Serial lines

By default, the Arduino D3 (Serial Tx) is connected to the Radio UART_RX, and the Arduino D2 (Serial Rx) is connected to the Radio UART_TX. By cutting between the pads marked by an asterisk in the Serial_TX and Serial_RX bank, these links can be severed, and a new connection made for each UART line by adding solder to bridge one pair of solder jumpers for each direction.

Only make connetions across one of each direction at a time to prevent multiplexing the digital pins on the Arduino, and don't connect both TX and RX to the same pin, as this will make communication very difficult!  
