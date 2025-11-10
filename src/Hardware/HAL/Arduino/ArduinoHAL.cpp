#include "ArduinoHAL.h"
#include "ArduinoHALTone.h"
#include "ArduinoHALLedControl.h"

/**
 * @brief Creates a new ArduinoHALServo instance.
 * 
 * @return A pointer to the newly created HALServo instance.
 */
HALServo* ArduinoHAL::newServo() {
    return new ArduinoHALServo();
}

/**
 * @brief Creates a new ArduinoHALTone instance.
 * 
 * @return A pointer to the newly created HALTone instance.
 */
HALTone* ArduinoHAL::newTone() {
    return new ArduinoHALTone();
}

/**
 * @brief Creates a new ArduinoHALLedControl instance.
 * 
 * @param dataPin The data pin number.
 * @param clkPin The clock pin number.
 * @param csPin The chip select pin number.
 * @return A pointer to the newly created HALLedControl instance.
 */
HALLedControl* ArduinoHAL::newLedControl(PinNumber dataPin, PinNumber clkPin, PinNumber csPin) {
    return new ArduinoHALLedControl(dataPin, clkPin, csPin);
}