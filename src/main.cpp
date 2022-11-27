/**************************************************************************/
/*! 
    @file     iso14443a_uid.pde
    @author   Adafruit Industries
	@license  BSD (see license.txt)
    This example will attempt to connect to an ISO14443A
    card or tag and retrieve some basic information about it
    that can be used to determine what type of card it is.   
   
    Note that you need the baud rate to be 115200 because we need to print
	out the data and read from the card at the same time!
This is an example sketch for the Adafruit PN532 NFC/RFID breakout boards
This library works with the Adafruit NFC breakout 
  ----> https://www.adafruit.com/products/364
 
Check out the links above for our tutorials and wiring diagrams 
These chips use SPI or I2C to communicate.
Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!
*/
/**************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include "pn532.h"
#include "netcom.h"

// #define I2C_Freq 100000

// #define SDA_0 18
// #define SCL_0 19

// TwoWire I2C_0 = TwoWire(0); // change iic pins

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10); // for Leonardo/Micro/Zero
  Serial.println("Hello!\n");

  // I2C_0.begin(SDA_0 , SCL_0 , I2C_Freq);

  pn532Init();
  initWiFi();
  getRRSI();
}

void loop(void) {
  pn532Scan();
}