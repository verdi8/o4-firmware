#pragma once

#include <Arduino.h>

class HAL {
public:
    void tone(uint8_t pin, unsigned int frequency, unsigned long duration = 0);
    void notone(uint8_t pin);
};

