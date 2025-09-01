#pragma once

#include "AngleStrategy.h"

class LinearAngleStrategy : public AngleStrategy {
private:
    /**
     * The speed of the servo movement in degrees per second.
     * This is used to calculate the time it takes to reach the target angle.
     */
    unsigned int speed;

    /**
     * The angle to which the servo will rotate.
     */
    unsigned int targetAngle;

    /**
     * The start time of the rotation.
     * This is used to determine if the servo has reached the target angle.
     */
    unsigned long startTime;

public:
    /**
     * Constructor to initialize the LinearAngleStrategy.
     */
    LinearAngleStrategy();

    /**
     * Sets the target angle for the servo.
     * @param angle The angle to which the servo will rotate (0 to 180 degrees).
     * @return A pointer to the LinearAngleStrategy instance for method chaining.
     */
    LinearAngleStrategy* rotateTo(unsigned int currentTime, unsigned int angle);

    /**
     * Computes the angle based on the current time.
     * @param currentTime The current time in milliseconds.
     * @return The target angle for the servo.
     */
    unsigned int computeNextAngle(unsigned int currentAngle, unsigned long currentTime) override;

    /**
     * Checks if the servo has reached the target angle.
     * @return True if the servo is ready to move to the target angle, false otherwise.
     */
    bool isDone(unsigned int currentAngle, unsigned long currentTime) override;

};
