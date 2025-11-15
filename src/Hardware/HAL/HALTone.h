#pragma once

#include "HALTypes.h"

/**
 * @brief Abstract interface for tone generation.
 * 
 * This interface defines methods for generating tones on a specific pin.
 */
class HALTone {
public:
    /**
     * @brief Generate a tone on the specified pin.
     * 
     * @param pin The pin number where the tone will be generated.
     * @param frequency The frequency of the tone in Hertz.
     * @param duration The duration of the tone in milliseconds (default is 0 for indefinite).
     */
    virtual void tone(unsigned int frequency, unsigned long duration = 0) = 0;

    /**
     * @brief Stop the tone on the specified pin.
     * 
     * @param pin The pin number where the tone will be stopped.
     */
    virtual void noTone() = 0;
};

