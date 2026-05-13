#include "ArduinoHAL.h"
#include "ArduinoHALSoftwareSerial.h"
#include "ArduinoHALTone.h"
#include "ArduinoHALLedControl.h"
#include "ArduinoHALProgramSpaceHelper.h"
#include "ArduinoHALSystem.h"

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
HALTone* ArduinoHAL::newTone(PinNumber buzzerPin) {
    return new ArduinoHALTone(buzzerPin);
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

/**
 * @brief Creates a new ArduinoHALSystem instance.
 *
 * @return A pointer to the newly created HALSystem instance.
 */
HALSystem* ArduinoHAL::newSystem() {
    return new ArduinoHALSystem();
}

/**
 * @brief Creates a new ArduinoHALSoftwareSerial instance.
 *
 * @param rxPin The receive pin number.
 * @param txPin The transmit pin number.
 * @return A pointer to the newly created HALSoftwareSerial instance.
 */
HALSoftwareSerial* ArduinoHAL::newSoftwareSerial(PinNumber rxPin, PinNumber txPin) {
    return new ArduinoHALSoftwareSerial(rxPin, txPin);
}

/**
 * @brief Creates a new ArduinoHALProgramSpaceHelper instance.
 * 
 * @return A pointer to the newly created HALProgramSpaceHelper instance.
 */
HALProgramSpaceHelper* ArduinoHAL::newProgramSpaceHelper() {
    return new ArduinoHALProgramSpaceHelper();
}
