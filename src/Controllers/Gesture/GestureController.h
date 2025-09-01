#ifndef GESTURECONTROLLER_H
#define GESTURECONTROLLER_H

#include <Arduino.h>
#include "Servo/ServoController.h"
#include "Controllers/Controller.h" // Include the Controller interface
#include "Controllers/TimeProvider.h"

/**
 * @class GestureController
 * @brief Controls the gestures of a robot using multiple ServoController instances.
 */
class GestureController : public Controller { // Implement the Controller interface
private:
    TimeProvider* timeProvider; // Pointer to the TimeProvider for getting current time
    ServoController* frontRightHip; // Servo controller for the front right hip joint.
    ServoController* frontLeftHip;  // Servo controller for the front left hip joint.
    ServoController* frontRightLeg; // Servo controller for the front right leg joint.
    ServoController* frontLeftLeg;  // Servo controller for the front left leg joint.
    ServoController* backRightHip;  // Servo controller for the back right hip joint.
    ServoController* backLeftHip;   // Servo controller for the back left hip joint.
    ServoController* backRightLeg;  // Servo controller for the back right leg joint.
    ServoController* backLeftLeg;   // Servo controller for the back left leg joint.
    ServoController* all[8];

public:
    /**
     * @brief Constructs a GestureController with the specified servo pins.
     * 
     * @param frontRightHipPin Pin for the front right hip servo.
     * @param frontLeftHipPin Pin for the front left hip servo.
     * @param frontRightLegPin Pin for the front right leg servo.
     * @param frontLeftLegPin Pin for the front left leg servo.
     * @param backRightHipPin Pin for the back right hip servo.
     * @param backLeftHipPin Pin for the back left hip servo.
     * @param backRightLegPin Pin for the back right leg servo.
     * @param backLeftLegPin Pin for the back left leg servo.
     */
    GestureController(
        TimeProvider* timeProvider,
        PIN_NUMBER frontRightHipPin,
        PIN_NUMBER frontLeftHipPin,
        PIN_NUMBER frontRightLegPin,
        PIN_NUMBER frontLeftLegPin,
        PIN_NUMBER backRightHipPin,
        PIN_NUMBER backLeftHipPin,
        PIN_NUMBER backRightLegPin,
        PIN_NUMBER backLeftLegPin
    );

    /**
     * @brief Moves the robot to its home position.
     */
    void home();

    /**
     * @brief Makes the robot walk using the configured servo controllers.
     */
    void walk();

    /**
     * @brief Updates the state of the GestureController.
     * 
     * @param currentTime The current time in milliseconds.
     */
    void update() override; // Override the update method from Controller

    /**
     * @brief Checks if the current gesture is complete.
     * 
     * @param currentTime The current time in milliseconds.
     * @return true if the gesture is complete, false otherwise.
     */
    bool isDone() override; // Override the isDone method from Controller
};

#endif // GESTURECONTROLLER_H