#pragma once

#include <Arduino.h>
#include "Hardware/HAL/HAL.h"
#include "Servo/ServoController.h"
#include "Controllers/Controller.h" // Include the Controller interface
#include "Controllers/TimeProvider.h"

/**
 * @class KinematicController
 * @brief Controls the gestures of a robot using multiple ServoController instances.
 */
class KinematicController : public Controller { // Implement the Controller interface
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
     * @brief Constructs a KinematicController with the specified servo pins.
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
    KinematicController(
        HAL* hal,
        TimeProvider* timeProvider,
        PinNumber frontRightHipPin,
        PinNumber frontLeftHipPin,
        PinNumber frontRightLegPin,
        PinNumber frontLeftLegPin,
        PinNumber backRightHipPin,
        PinNumber backLeftHipPin,
        PinNumber backRightLegPin,
        PinNumber backLeftLegPin
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
     * @brief Updates the state of the KinematicController.
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
