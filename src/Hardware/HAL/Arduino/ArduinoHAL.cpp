#include "ArduinoHAL.h"

/**
 * @brief Creates a new ArduinoHALServo instance.
 * 
 * @return A pointer to the newly created HALServo instance.
 */
HALServo* ArduinoHAL::newServo() {
    return new ArduinoHALServo();
}
