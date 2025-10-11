#pragma once

#include "../HAL.h"
#include "ArduinoHALServo.h"

/**
 * @brief ArduinoHAL is a concrete implementation of the HAL interface
 * for Arduino-based hardware.
 */
class ArduinoHAL : public HAL {
public:
    /**
     * @brief Creates a new ArduinoHALServo instance.
     * 
     * @return A pointer to the newly created HALServo instance.
     */
    HALServo* newServo() override;
};
