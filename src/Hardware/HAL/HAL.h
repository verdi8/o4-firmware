#pragma once

#include <Arduino.h>
#include "HALServo.h" // Include the header file where HALServo is defined

/**
 * The HAL (Hardware Abstraction Layer) interface provides an abstraction
 * for hardware-specific operations. It defines the methods that must be
 * implemented by any hardware-specific class to interact with servos and
 * other peripherals.
 */
class HAL {
public:
    /**
     * Creates a new HALServo instance.
     * @return A pointer to the newly created HALServo instance.
     */
    virtual HALServo* newServo() = 0;

};

