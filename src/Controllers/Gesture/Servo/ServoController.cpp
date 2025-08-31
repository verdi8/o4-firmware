#include "ServoController.h"
#include "logger.h"

#define INIT_ANGLE 90    // Initial angle for the servo
#define INIT_DELAY 300   // Delay to allow the servo to reach the initial position

ServoController::ServoController(PIN_NUMBER pin)
{
    this->pin = pin;     // Set the pin number
    servo = new Servo(); // Create a new Servo object

    oscillatingAngleStrategyInstance = new OscillatingAngleStrategy();  // Keep an instance of OscillatingAngleStrategy
    linearAngleStrategyInstance = new LinearAngleStrategy();          // Keep an instance of LinearAngleStrategy
    currentAngleStrategy = nullptr;                                     // Initialize the current angle strategy to nullptr

    initPosition();                                                     // Initialize the servo to a default position
}

void ServoController::rotateTo(unsigned long currentTime, int angle)
{
    DEBUG___("Rotating servo on pin: ", pin, " to target angle: ", angle);
    this->currentAngleStrategy = this->linearAngleStrategyInstance->rotateTo(currentTime, angle); // Set the current angle strategy to oscillating
}

void ServoController::oscillate(unsigned long currentTime, int amplitude, int period, int offset, int phase)
{
    this->currentAngleStrategy = this->oscillatingAngleStrategyInstance->oscilliate(currentTime, amplitude, period, offset, phase);
}

void ServoController::stop()
{
    // servo->detach();                      // Detach the servo to stop it from moving
    this->currentAngleStrategy = nullptr; // Clear the current angle strategy
}

void ServoController::update(unsigned long currentTime)
{
    if (!this->currentAngleStrategy)
    {
        // If no strategy is set, do nothing
        return;
    }

    // Compute the angle based on the current time
    unsigned int angle = this->currentAngleStrategy->computeNextAngle(this->currentAngle, currentTime);

    // Ensure the angle is within valid bounds (0 to 180 degrees)
    if (angle < 0)
    {
        angle = 0;
    }
    if (angle > 180)
    {
        angle = 180;
    }


    // Attach the servo if it is not already attached
    if (!servo->attached())
    {
        servo->attach(pin); // Attach the servo to the specified pin
    }    

    // Rotate the servo to the computed angle
    if (currentAngle != angle)
    {
        // DEBUG_(pin, angle);
        currentAngle = angle; // Update the last angle
        servo->write(angle);
    }
   

    // Check if the movement is done
    if (this->currentAngleStrategy->isDone(currentAngle, currentTime))
    {
        // If the movement is done, stop the servo
        stop();
    }

}

bool ServoController::isDone(unsigned long currentTime)
{
    // If no strategy is set, the servo is considered done
    if (!this->currentAngleStrategy)
    {
        return true;
    }

    // Check if the current strategy reports that the movement is done
    return this->currentAngleStrategy->isDone(this->currentAngle, currentTime);
}

void ServoController::initPosition() {
    servo->write(INIT_ANGLE);     // Set the servo to the initial position
    servo->attach(pin);           // Attach the servo to the specified pin
    currentAngle = 90;            // Update the current angle to the initial position
    delay(INIT_DELAY);            // Wait for the servo to reach the position (and not move all the servos at the same time, to reduce power consumption)
    servo->detach();
}
