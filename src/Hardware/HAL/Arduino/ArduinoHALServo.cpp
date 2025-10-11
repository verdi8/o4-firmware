#include "ArduinoHALServo.h"
#include <Servo.h>

// Constructor
ArduinoHALServo::ArduinoHALServo() {
    servo = new Servo();
}

/**
 * @brief Attach the servo to a specific pin.
 * 
 * @param pin The pin number to which the servo is connected.
 */
void ArduinoHALServo::attach(uint8_t pin) {
    servo->attach(pin);
}

/**
 * @brief Detach the servo, stopping its control.
 */
void ArduinoHALServo::detach() {
    servo->detach();
}

/**
 * @brief Write an angle (in degrees) to the servo.
 * 
 * @param value The angle to set the servo to, in degrees (0-180).
 */
void ArduinoHALServo::write(int value) {
    servo->write(value);
}

/**
 * @brief Check if the servo is currently attached.
 * 
 * @return true if the servo is attached, false otherwise.
 */
bool ArduinoHALServo::attached() {
    return servo->attached();
}
