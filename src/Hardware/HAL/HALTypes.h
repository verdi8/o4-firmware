#pragma once

#if defined(ARDUINO) 
    #include <Arduino.h>
#else 
    
    #include <stdint.h>
    
    // Redefines Arduino types
    typedef uint8_t  byte;
    typedef unsigned int  word;

    #define PROGMEM
#endif

typedef uint8_t PinNumber;
