#ifndef PN532_H_
#define PN532_H_

// #include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>

#define PN532_IRQ   (2)
#define PN532_RESET (4)  // Not connected by default on the NFC Shield

void pn532Init(void);

void pn532Scan(void);

#endif