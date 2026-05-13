#pragma once

// Logging macros

#define DEBUG_MODE 1 // Set to 1 to enable debug messages, 0 to disable

#if defined(ARDUINO) 
    #include <Arduino.h>
    #define PRINT(x) Serial.print(x)
    #define PRINTLN(x) Serial.println(x)
#else
    #include <iostream>
    #define PRINT(x) std::cout << x
    #define PRINTLN(x) std::cout << x << std::endl
#endif

#if DEBUG_MODE
#define DEBUG(x) PRINT("[DEBUG] "); PRINTLN(x)
#define DEBUG_(x,y) PRINT("[DEBUG] "); PRINT(x); PRINTLN(y)
#define DEBUG__(x,y,z) PRINT("[DEBUG] "); PRINT(x); PRINT(y); PRINTLN(z)
#define DEBUG___(x,y,z,w) PRINT("[DEBUG] "); PRINT(x); PRINT(y); PRINT(z); PRINTLN(w)
#else
#define DEBUG(x)
#define DEBUG_(x,y)
#define DEBUG__(x,y,z)
#define DEBUG___(x,y,z,w)
#endif

#define INFO(x) PRINT("[INFO] "); PRINTLN(x)
#define INFO_(x,y) PRINT("[INFO] "); PRINT(x); PRINTLN(y)
#define INFO__(x,y,z) PRINT("[INFO] "); PRINT(x); PRINT(y); PRINTLN(z)
#define INFO___(x,y,z,w) PRINT("[INFO] "); PRINT(x); PRINT(y); PRINT(z); PRINTLN(w)


#define ERROR(x) PRINT("[ERROR] "); PRINTLN(x)
#define ERROR_(x,y) PRINT("[ERROR] "); PRINT(x); PRINTLN(y)
#define ERROR__(x,y,z) PRINT("[ERROR] "); PRINT(x); PRINT(y); PRINTLN(z)
#define ERROR___(x,y,z,w) PRINT("[ERROR] "); PRINT(x); PRINT(y); PRINT(z); PRINTLN(w)
