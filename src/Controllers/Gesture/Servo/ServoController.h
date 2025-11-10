#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

#include "Config.h"
#include "Hardware/HAL/HAL.h"
#include "AngleCalculator/AngleCalculator.h"
#include "AngleCalculator/LinearAngleCalculator.h"
#include "AngleCalculator/OscillatingAngleCalculator.h"
#include "Controllers/Controller.h" // Include the Controller interface
#include "Controllers/TimeProvider.h"

/**
 * ServoController class to manage a servo motor.
 * It provides methods to rotate the servo to a specific angle and stop it.
 * The servo is controlled using the Servo library.
 */
class ServoController : public Controller // Implement the Controller interface
{
    private:
        TimeProvider* timeProvider; // Pointer to the TimeProvider for getting current time

        /** 
         * The pin number to which the servo is connected.
         * This should be set in the constructor.
         */
        PinNumber pin;

        /** 
         * The Servo object that controls the servo motor.
         * This is initialized in the constructor.
         */
        HALServo* servo;

        /**
         * The current strategy for controlling the angle of the servo.
         */
        AngleCalculator* currentAngleCalculator = nullptr;

        /**
         * An instance of LinearAngleCalculator to handle linear movements.
         */
        LinearAngleCalculator* linearAngleCalculatorInstance; 

        /**
         * An instance of OscillatingAngleCalculator to handle oscillating movements.
         */
        OscillatingAngleCalculator* oscillatingAngleCalculatorInstance;

        /**
         * Th
         * This is used to track the last position of the servo.
         */
        unsigned int currentAngle;

    public:
        /** 
         * Constructor to initialize the pin number
         * @param pin The pin number to which the servo is connected
         */
        ServoController(HAL* hal, TimeProvider* timeProvider, PinNumber pin);

        /**
         * Rotate the servo to a specified angle.
         * @param targetAngle The angle to rotate the servo to (0 to 180 degrees)
         */
        void rotateTo(int targetAngle);

        /**
         * Set the oscillation parameters for the servo.
         * This will make the servo oscillate between the specified parameters.
         * @param currentTime The current time in milliseconds
         * @param amplitude The amplitude of the oscillation
         * @param period The period of the oscillation in milliseconds
         * @param offset The offset from the center angle
         * @param phase The phase shift of the oscillation
         */
        void oscillate(int amplitude, int period, int offset, int phase);

        /**
         * Update the servo position based on the current time.
         * @param currentTime The current time in milliseconds
         */
        void update() override; // Override the update method from Controller
    
        /**
         * Check if the servo has completed its movement.
         * @param currentTime The current time in milliseconds
         * @return true if the movement is complete, false otherwise.
         */
        bool isDone() override; // Override the isDone method from Controller

        /**
         * Stops the servo moving.
         */
        void stop();

    private:
        /**
         * Reset the servo position to the initial state.
         */
        void initPosition();
};

#endif // SERVOCONTROLLER_H
