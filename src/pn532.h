#ifndef PN532_H_
#define PN532_H_

// #include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include "main.h"

#define PN532_IRQ   (2)
#define PN532_RESET (4)  // Not connected by default on the NFC Shield

void pn532Init(void);

boolean pn532Scan(void);

extern int freq;
extern int channel;//通道号，取值0 ~ 15
extern int resolution;//计数位数，2的8次幂=256

extern int ledState;               // ledState used to set the LED
extern int previousButtonLState;    // will store last time button was updated
extern int previousButtonRState;    // will store last time button was updated
extern unsigned long previousMillis; // will store last time LED was updated

extern int signUpMode;

#endif