#ifndef LOGGER_H
#define LOGGER_H
#include <Arduino.h>

// Logging macros

#define DEBUG_MODE 1 // Set to 1 to enable debug messages, 0 to disable

#if DEBUG_MODE
#define DEBUG(x) Serial.print("[DEBUG] "); Serial.println(x)
#define DEBUG_(x,y) Serial.print("[DEBUG] "); Serial.print(x); Serial.println(y)
#define DEBUG__(x,y,z) Serial.print("[DEBUG] "); Serial.print(x); Serial.print(y); Serial.println(z)
#define DEBUG___(x,y,z,w) Serial.print("[DEBUG] "); Serial.print(x); Serial.print(y); Serial.print(z); Serial.println(w)
#else
#define DEBUG(x)
#define DEBUG_(x,y)
#define DEBUG__(x,y,z)
#define DEBUG___(x,y,z,w)
#endif

#define INFO(x) Serial.print("[INFO] "); Serial.println(x)
#define ERROR(x) Serial.print("[ERROR] "); Serial.println(x)

#endif // LOGGER_H
