#include "LinearAngleStrategy.h"
#include <Arduino.h>

#define DEFAULT_SPEED 90 // Default speed in degrees per second

LinearAngleStrategy::LinearAngleStrategy() {
    this->speed = DEFAULT_SPEED; // Set the speed of the servo movement
    this->targetAngle = 0; // Initialize target angle to 0
}
  
LinearAngleStrategy* LinearAngleStrategy::rotateTo(unsigned int currentTime, unsigned int angle) {
    // Set the start time for the rotation
    this->startTime = currentTime; // Store the current time as the start time
    
    // Set the target angle for the servo
    if (angle < 0) {
        this->targetAngle = 0; // Ensure angle is not less than 0
    } else if (angle > 180) {
        this->targetAngle = 180; // Ensure angle is not more than 180
    } else {
        this->targetAngle = angle; // Set the target angle
    }
    return this; // Return the instance for method chaining
}


unsigned int LinearAngleStrategy::computeNextAngle(unsigned int currentAngle, unsigned long currentTime) {
    // Calculate and return the next angle according the target angle and speed
    unsigned long elapsedTime = currentTime - startTime; // Calculate the elapsed time since the start of rotation
    int angleChange = (elapsedTime * speed) / 1000; // Calculate the angle change based on speed and elapsed time
    if (currentAngle < targetAngle) {
        // If current angle is less than target angle, increase the angle
        return min(currentAngle + angleChange, targetAngle);
    } else if (currentAngle > targetAngle) {
        // If current angle is greater than target angle, decrease the angle
        return max(currentAngle - angleChange, targetAngle);
    } else {
        // 
        return targetAngle;
    }
}

bool LinearAngleStrategy::isDone(unsigned int currentAngle, unsigned long currentTime) {
    // Check if the current angle is equal to the target angle
    return currentAngle == targetAngle;
}