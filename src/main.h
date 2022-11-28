#ifndef MAIN_H_
#define MAIN_H_

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#include "pn532.h"
#include "netcom.h"
#include "oled.h"

// #define I2C_Freq 100000

// #define SDA_0 18
// #define SCL_0 19

// TwoWire I2C_0 = TwoWire(0); // change iic pins

#define BUZZER_PIN 5

#define NETWORK_LED 14
#define CARD_LED 13
#define BUTTON_PIN_L 26     // ESP32 pin GIOP16 connected to button Left
#define BUTTON_PIN_R 27     // ESP32 pin GIOP16 connected to button Right
#define BLINK_INTERVAL 1000 // interval at which to blink LED (milliseconds)

#endif