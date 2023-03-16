#ifndef gps_h
#define gps_h

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 4800;

// instance of TinyGPSPlus
TinyGPSPlus gps;

// serial connection to GPS device
SoftwareSerial ss(RXPin, TXPin);

#endif