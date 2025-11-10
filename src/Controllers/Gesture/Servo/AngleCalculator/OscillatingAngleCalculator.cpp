#include "OscillatingAngleCalculator.h"
#include <math.h>

/**
 * Converts degrees to radians.
 * @param degrees The angle in degrees.
 * @return The angle in radians.
 */
double inline deg2rad(int degrees) {
    return ((double) degrees) * (M_PI / 180.0);
}


/**
 * @brief Constructor to initialize the OscillatingAngleCalculator.
 */
OscillatingAngleCalculator::OscillatingAngleCalculator() {
    startTime = 0; // Initialize start time to 0.
    amplitude = 0; // Initialize amplitude to 0.
    period = 0; // Initialize period to 0.
    offset = 0; // Initialize offset to 0.
    phase = 0; // Initialize phase to 0.
}

/**
 * Sets the oscillation parameters for the servo.
 * This will make the servo oscillate between the specified parameters.
 */
OscillatingAngleCalculator* OscillatingAngleCalculator::oscilliate(unsigned long currentTime, int amplitude, int period, int offset, int phase) {
    this->startTime = currentTime; // Set the start time of the oscillation.
    this->amplitude = amplitude;
    this->period = period;
    this->offset = offset;
    this->phase = phase;
    return this; // Return the instance for method chaining.
}

/**
 * Computes the angle based on the current time.
 * @param currentTime The current time in milliseconds.
 * @param currentAngle The current angle of the servo (not used in this strategy).
 * @return The target angle for the servo.
 */
unsigned int OscillatingAngleCalculator::calculateNextAngle(unsigned int currentAngle, unsigned long currentTime) {
    unsigned long deltaTime = currentTime - startTime; // Calculate the elapsed time since the start of oscillation.
    double timeInRadians = (2 * M_PI * deltaTime / period) + deg2rad(phase); // Convert elapsed time to radians.
    return offset + amplitude * sin(timeInRadians);
}

/**
 * Checks if the mouvement is done.
 */
bool OscillatingAngleCalculator::isDone(unsigned int currentAngle, unsigned long currentTime) {
    // Oscillation is continuous, so it is never "done."
    return false;
}

