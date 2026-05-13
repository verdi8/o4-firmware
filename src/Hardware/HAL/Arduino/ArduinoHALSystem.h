#pragma once

#include "../HALSystem.h"

/**
 * @brief Arduino-specific HALSystem implementation.
 */
class ArduinoHALSystem : public HALSystem {
public:
    unsigned long millis() override;
    void delay(unsigned long durationMs) override;
};