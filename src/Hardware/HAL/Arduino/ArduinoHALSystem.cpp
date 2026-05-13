#include "ArduinoHALSystem.h"

#include <Arduino.h>

unsigned long ArduinoHALSystem::millis()
{
    return ::millis();
}

void ArduinoHALSystem::delay(unsigned long durationMs)
{
    ::delay(durationMs);
}