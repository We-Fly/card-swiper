#ifndef NETCONFIG_HPP_
#define NETCONFIG_HPP_

#include "HTTPClient.h"

// Set your Wi-Fi SSID and Password
const char *ssid = "HUAWEI-801";
const char *password = "jiaobaba233";

// Your Domain name with URL path or IP address with path
String serverName = "http://192.168.10.106:8001/test";


// Set true/false to enable/disable static IP settings
#define USE_STATIC_IP true

#if USE_STATIC_IP
// Set your Static IP address
IPAddress local_IP(192, 168, 10, 100);
// Set your Gateway IP address
IPAddress gateway(192, 168, 10, 1);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional
#endif

#endif