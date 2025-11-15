#pragma once

#include <Arduino.h>
#include "../HAL.h"
#include "ArduinoHALServo.h"

/**
 * @brief Arduino-specific implementation of the HAL interface.
 * 
 * This class provides methods to create Arduino-specific hardware abstraction layer instances.
 */
class ArduinoHAL : public HAL {
public:
    /**
     * @brief Creates a new ArduinoHALServo instance.
     * 
     * @return A pointer to the newly created HALServo instance.
     */
    HALServo* newServo() override;

    /**
     * @brief Creates a new ArduinoHALTone instance.
     * 
     * @return A pointer to the newly created HALTone instance.
     */
    HALTone* newTone(PinNumber buzzerPin) override;

    /**
     * @brief Creates a new ArduinoHALLedControl instance.
     * 
     * @param dataPin The data pin number.
     * @param clkPin The clock pin number.
     * @param csPin The chip select pin number.
     * @return A pointer to the newly created HALLedControl instance.
     */
    HALLedControl* newLedControl(PinNumber dataPin, PinNumber clkPin, PinNumber csPin) override;

    /**
     * @brief Creates a new ArduinoHALProgramSpaceHelper instance.
     * 
     * @return A pointer to the newly created HALProgramSpaceHelper instance.
     */
    HALProgramSpaceHelper* newProgramSpaceHelper() override;
};
