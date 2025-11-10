#pragma once

#include "Config.h"

/**
 * @brief HALServo is an abstract interface for controlling servo motors.
 * 
 * This interface provides methods to attach a servo to a pin, detach it,
 * write angles to the servo, and check if the servo is currently attached.
 */
class HALServo {
public:
    /**
     * @brief Attach the servo to a specific pin.
     * 
     * @param pin The pin number to which the servo is connected.
     */
    virtual void attach(PinNumber pin) = 0;

    /**
     * @brief Detach the servo, stopping its control.
     */
    virtual void detach() = 0;

    /**
     * @brief Write an angle (in degrees) to the servo.
     * 
     * @param value The angle to set the servo to, in degrees (0-180).
     */
    virtual void write(int value) = 0;

    /**
     * @brief Check if the servo is currently attached.
     * 
     * @return true if the servo is attached, false otherwise.
     */
    virtual bool attached() = 0;
};
