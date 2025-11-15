#include "ArduinoHALTone.h"
#include <Arduino.h>

/**
 * @brief Constructor for ArduinoHALTone.
 * 
 * @param buzzerPin The pin number where the buzzer is connected.
 */
ArduinoHALTone::ArduinoHALTone(PinNumber buzzerPin)
    : buzzerPin(buzzerPin) 
    {
    // Constructor can initialize the pin if needed
    ::pinMode(buzzerPin, OUTPUT);
}

/**
 * @brief Generate a tone on the specified pin.
 * 
 * @param pin The pin number where the tone will be generated.
 * @param frequency The frequency of the tone in Hertz.
 * @param duration The duration of the tone in milliseconds (default is 0 for indefinite).
 */
void ArduinoHALTone::tone(unsigned int frequency, unsigned long duration) {
    ::tone(buzzerPin, frequency, duration);
}

/**
 * @brief Stop the tone on the specified pin.
 * 
 * @param pin The pin number where the tone will be stopped.
 */
void ArduinoHALTone::noTone() {
    ::noTone(buzzerPin);
}

