#ifndef ANGLESTRATEGY_H
#define ANGLESTRATEGY_H

/**
 * Interface for angle strategies used by the ServoController.
 * This interface defines the methods that any angle strategy must implement.
 */
class AngleStrategy {
public:

    /**
     * @brief Computes the angle for a servo motor based on the current time.
     */
    virtual unsigned int computeNextAngle(unsigned int currentAngle, unsigned long currentTime) = 0;

    /**
     * Checks if the movement is done.
     */
    virtual bool isDone(unsigned int currentAngle, unsigned long currentTime) = 0;
};

#endif // ANGLESTRATEGY_H