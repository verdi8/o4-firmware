#include "BodyController.h"
#include "logger.h"

// Behaviour parameters
#define DEFAULT_OSCILLIATION_PERIOD 1000 // in milliseconds

BodyController::BodyController(
    HAL* hal,
    TimeProvider *timeProvider,
    PinNumber frontRightHipPin,
    PinNumber frontLeftHipPin,
    PinNumber frontRightLegPin,
    PinNumber frontLeftLegPin,
    PinNumber backRightHipPin,
    PinNumber backLeftHipPin,
    PinNumber backRightLegPin,
    PinNumber backLeftLegPin) : timeProvider(timeProvider)
{

    frontRightHip = new ServoController(hal, timeProvider, frontRightHipPin);
    frontLeftHip = new ServoController(hal, timeProvider, frontLeftHipPin);
    frontRightLeg = new ServoController(hal, timeProvider, frontRightLegPin);
    frontLeftLeg = new ServoController(hal, timeProvider, frontLeftLegPin);
    backRightHip = new ServoController(hal, timeProvider, backRightHipPin);
    backLeftHip = new ServoController(hal, timeProvider, backLeftHipPin);
    backRightLeg = new ServoController(hal, timeProvider, backRightLegPin);
    backLeftLeg = new ServoController(hal, timeProvider, backLeftLegPin);

    all[0] = frontRightHip;
    all[1] = frontLeftHip;
    all[2] = frontRightLeg;
    all[3] = frontLeftLeg;
    all[4] = backRightHip;
    all[5] = backLeftHip;
    all[6] = backRightLeg;
    all[7] = backLeftLeg;
}

ServoController* BodyController::getFrontRightHip()
{
    return frontRightHip;
}

ServoController* BodyController::getFrontLeftHip()
{
    return frontLeftHip;
}

ServoController* BodyController::getFrontRightLeg()
{
    return frontRightLeg;
}
ServoController* BodyController::getFrontLeftLeg()
{
    return frontLeftLeg;
}

ServoController* BodyController::getBackRightHip()
{
    return backRightHip;
}

ServoController* BodyController::getBackLeftHip()
{
    return backLeftHip;
}

ServoController* BodyController::getBackRightLeg()
{
    return backRightLeg;
}

ServoController* BodyController::getBackLeftLeg()
{
    return backLeftLeg;
}

void BodyController::update()
{
    for (int i = 0; i < 8; i++)
    {
        all[i]->update();
    }
}

bool BodyController::isDone()
{
    for (int i = 0; i < 8; i++)
    {
        if (!all[i]->isDone())
        {
            return false;
        }
    }
    return true;
}
