#ifndef NETCOM_HPP_
#define NETCOM_HPP_

#include <WiFi.h>
#include <HTTPClient.h>

void initWiFi();

int8_t getRRSI();

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info);

void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info);

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info);

void sendID(uint8_t * uid, uint8_t uidlength);

#endif