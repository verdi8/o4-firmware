#pragma once

#include "Hardware/HAL/HAL.h"
#include "Servo/ServoController.h"
#include "Controllers/Controller.h" // Include the Controller interface
#include "Controllers/TimeProvider.h"

/**
 * @class BodyController
 * @brief Controls the gestures of a robot using multiple ServoController instances.
 */
class BodyController : public Controller { // Implement the Controller interface
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
     * @brief Constructs a BodyController with the specified servo pins.
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
    BodyController(
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
     * @brief Gets the front right hip ServoController.
     * 
     * @return Pointer to the front right hip ServoController.
     */
    ServoController* getFrontRightHip();

    /**
     * @brief Gets the front left hip ServoController.
     * 
     * @return Pointer to the front left hip ServoController.
     */
    ServoController* getFrontLeftHip();

    /**
     * @brief Gets the front right leg ServoController.
     * 
     * @return Pointer to the front right leg ServoController.
     */
    ServoController* getFrontRightLeg();

    /**
     * @brief Gets the front left leg ServoController.
     * 
     * @return Pointer to the front left leg ServoController.
     */
    ServoController* getFrontLeftLeg();

    /**
     * @brief Gets the back right hip ServoController.
     * 
     * @return Pointer to the back right hip ServoController.
     */
    ServoController* getBackRightHip();

    /**
     * @brief Gets the back left hip ServoController.
     * 
     * @return Pointer to the back left hip ServoController.
     */
    ServoController* getBackLeftHip();

    /**
     * @brief Gets the back right leg ServoController.
     * 
     * @return Pointer to the back right leg ServoController.
     */
    ServoController* getBackRightLeg();

    /**
     * @brief Gets the back left leg ServoController.
     * 
     * @return Pointer to the back left leg ServoController.
     */
    ServoController* getBackLeftLeg();

    /**
     * @brief Updates the state of the BodyController.
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
