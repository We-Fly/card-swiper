#ifndef NETCONFIG_H_
#define NETCONFIG_H_

#include "HTTPClient.h"

const char *ssid = "CHANGE_TO_YOUR_WIFI_SSID";
const char *password = "CHANGE_TO_YOUR_WIFI_PASSWORD";

// Your Domain name with URL path or IP address with path
String serverName = "http://192.168.10.106:8001/test";

// Set your Static IP address
IPAddress local_IP(192, 168, 10, 100);
// Set your Gateway IP address
IPAddress gateway(192, 168, 10, 1);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional

#endif