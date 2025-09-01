#pragma once
#include "AngleStrategy.h"
#include "Controllers/TimeProvider.h"

class OscillatingAngleStrategy : public AngleStrategy {
private:
    /**
     * The start time of the oscillation.
     * This is used to calculate the angle based on the elapsed time.
     */
    unsigned long startTime;

    /**
     * The amplitude of the oscillation.
     */
    int amplitude;

    /**
     * The period of the oscillation in milliseconds.
     */
    int period;

    /**
     * The offset from the center angle.
     * This is the angle around which the oscillation occurs.
     */
    int offset;

    /**
     * The offset from the center angle.
     */
    int phase;



public:
    /**
     * Constructor to initialize the OscillatingAngleStrategy.
     */
    OscillatingAngleStrategy();

    /**
     * Sets the oscillation parameters for the servo.
     * This will make the servo oscillate between the specified parameters.
     * @param currentTime The current time in milliseconds.
     * @param amplitude The amplitude of the oscillation.
     * @param period The period of the oscillation in milliseconds.
     * @param offset The offset from the center angle.
     * @param phase The phase shift of the oscillation.
     * @return A pointer to the OscillatingAngleStrategy instance for method chaining.
     */
    OscillatingAngleStrategy* oscilliate(unsigned long currentTime, int amplitude, int period, int offset, int phase);
    /**
     * Computes the angle based on the current time.
     * @param currentTime The current time in milliseconds.
     * @return The target angle for the servo.
     */
    unsigned int computeNextAngle(unsigned int currentAngle, unsigned long currentTime) override;

    /**
     * Checks if the movement is done.
     */
    bool isDone(unsigned int currentAngle, unsigned long currentTime) override;

};

