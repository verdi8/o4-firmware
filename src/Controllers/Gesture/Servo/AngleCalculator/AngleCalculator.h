#pragma once

/**
 * @brief Interface for angle strategies used by the ServoController.
 * 
 * This interface defines the methods that any angle strategy must implement
 * to calculate servo motor angles and determine movement completion.
 */
class AngleCalculator {
public:

    /**
     * @brief Computes the next angle for a servo motor based on the current angle and time.
     * 
     * @param currentAngle The current angle of the servo motor.
     * @param currentTime The current time in milliseconds.
     * @return The next angle to set for the servo motor.
     */
    virtual unsigned int calculateNextAngle(unsigned int currentAngle, unsigned long currentTime) = 0;

    /**
     * @brief Checks if the movement is complete.
     * 
     * @param currentAngle The current angle of the servo motor.
     * @param currentTime The current time in milliseconds.
     * @return True if the movement is complete, false otherwise.
     */
    virtual bool isDone(unsigned int currentAngle, unsigned long currentTime) = 0;
};
