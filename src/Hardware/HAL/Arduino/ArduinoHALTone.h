#pragma once

#include "../HALTone.h"

/**
 * @brief Arduino-specific implementation of the HALTone interface.
 * 
 * This class provides methods to generate and stop tones using Arduino's tone library.
 */
class ArduinoHALTone : public HALTone {
public:

    /**
     * @brief Generate a tone on the specified pin.
     * 
     * @param pin The pin number where the tone will be generated.
     * @param frequency The frequency of the tone in Hertz.
     * @param duration The duration of the tone in milliseconds (default is 0 for indefinite).
     */
    void tone(PinNumber pin, unsigned int frequency, unsigned long duration = 0) override;

    /**
     * @brief Stop the tone on the specified pin.
     * 
     * @param pin The pin number where the tone will be stopped.
     */
    void noTone(PinNumber pin) override;
};
