#include "MovementActions.h"
#include "logger.h"

const int DEFAULT_OSCILLIATION_PERIOD = 1000; // in milliseconds

/**
 * @brief Constructor for MovementActions.
 */
MovementActions::MovementActions(BodyController* bodyController)
    : bodyController(bodyController) {
    // Constructor implementation (if needed)
}
/**
 * @brief Moves the robot to its home position.
 */
void MovementActions::home() {
    int testPosition = 90;
    DEBUG(F("Moving to home position"));
    this->bodyController->getFrontRightHip()->rotateTo(testPosition);
    this->bodyController->getFrontLeftHip()->rotateTo(testPosition);
    this->bodyController->getFrontRightLeg()->rotateTo(testPosition);
    this->bodyController->getFrontLeftLeg()->rotateTo(testPosition);
    this->bodyController->getBackRightHip()->rotateTo(testPosition);
    this->bodyController->getBackLeftHip()->rotateTo(testPosition);
    this->bodyController->getBackRightLeg()->rotateTo(testPosition);
    this->bodyController->getBackLeftLeg()->rotateTo(testPosition);
}

/**
 * @brief Makes the robot walk using the configured servo controllers.
 */
void MovementActions::walk() {
    int x_amp = 15;
    int z_amp = 20;
    int ap = 20;
    int hi = -0;
    this->bodyController->getFrontRightHip()->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + ap, 270);
    this->bodyController->getFrontLeftHip()->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - ap, 270);
    this->bodyController->getFrontRightLeg()->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - hi, 180);
    this->bodyController->getFrontLeftLeg()->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + hi, 180);
    this->bodyController->getBackRightHip()->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - ap, 90);
    this->bodyController->getBackLeftHip()->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + ap, 90);
    this->bodyController->getBackRightLeg()->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + hi, 180);
    this->bodyController->getBackLeftLeg()->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - hi, 180);
}
