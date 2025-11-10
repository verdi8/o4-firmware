#pragma once

#include <Servo.h>
#include "Hardware/HAL/HALServo.h"


/**
 * @brief ArduinoHALServo is a concrete implementation of the HALServo interface
 * using the Arduino Servo library.
 */
class ArduinoHALServo : public HALServo {
public:

    /**
     * @brief Attach the servo to a specific pin.
     * 
     * @param pin The pin number to which the servo is connected.
     */
    void attach(PinNumber pin) override;

    /**
     * @brief Detach the servo, stopping its control.
     */
    void detach() override;

    /**
     * @brief Write an angle (in degrees) to the servo.
     * 
     * @param value The angle to set the servo to, in degrees (0-180).
     */
    void write(int value) override;

    /**
     * @brief Check if the servo is currently attached.
     * 
     * @return true if the servo is attached, false otherwise.
     */
    bool attached() override;

private:
    Servo servo = Servo();
};
