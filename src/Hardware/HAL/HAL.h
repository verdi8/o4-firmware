#pragma once

#include "HALProgramSpaceHelper.h" // Include the header file for program space utilities
#include "HALTypes.h" // Include the header file where PinNumber is defined
#include "HALServo.h" // Include the header file where HALServo is defined
#include "HALTone.h" // Include the header file where HALTone is defined
#include "HALLedControl.h" // Include the header file where HALLedControl is defined



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

    /**
     * Creates a new HALTone instance.
     * @return A pointer to the newly created HALTone instance.
     */
    virtual HALTone* newTone(PinNumber buzzerPin) = 0;

    /**
     * Creates a new HALLedControl instance.
     * @param dataPin The data pin number.
     * @param clkPin The clock pin number.
     * @param csPin The chip select pin number.
     * @return A pointer to the newly created HALLedControl instance.
     */
    virtual HALLedControl* newLedControl(PinNumber dataPin, PinNumber clkPin, PinNumber csPin) = 0;

    /**
     * Creates a new HALProgramSpaceHelper instance.
     * @return A pointer to the newly created HALProgramSpaceHelper instance.
     */
    virtual HALProgramSpaceHelper* newProgramSpaceHelper() = 0;

};

