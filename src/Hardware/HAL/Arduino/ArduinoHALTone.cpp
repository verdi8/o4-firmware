#include "ArduinoHALTone.h"
#include <Arduino.h>

/**
 * @brief Generate a tone on the specified pin.
 * 
 * @param pin The pin number where the tone will be generated.
 * @param frequency The frequency of the tone in Hertz.
 * @param duration The duration of the tone in milliseconds (default is 0 for indefinite).
 */
void ArduinoHALTone::tone(PinNumber pin, unsigned int frequency, unsigned long duration) {
    ::tone(pin, frequency, duration);
}

/**
 * @brief Stop the tone on the specified pin.
 * 
 * @param pin The pin number where the tone will be stopped.
 */
void ArduinoHALTone::noTone(PinNumber pin) {
    ::noTone(pin);
}

