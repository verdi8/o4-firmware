#include "GestureController.h"

// Behaviour parameters
#define DEFAULT_OSCILLIATION_PERIOD 1000 // in milliseconds

GestureController::GestureController(
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
    frontRightHip = new ServoController(timeProvider, frontRightHipPin);
    frontLeftHip = new ServoController(timeProvider, frontLeftHipPin);
    frontRightLeg = new ServoController(timeProvider, frontRightLegPin);
    frontLeftLeg = new ServoController(timeProvider, frontLeftLegPin);
    backRightHip = new ServoController(timeProvider, backRightHipPin);
    backLeftHip = new ServoController(timeProvider, backLeftHipPin);
    backRightLeg = new ServoController(timeProvider, backRightLegPin);
    backLeftLeg = new ServoController(timeProvider, backLeftLegPin);
    all[0] = frontRightHip;
    all[1] = frontLeftHip;
    all[2] = frontRightLeg;
    all[3] = frontLeftLeg;
    all[4] = backRightHip;
    all[5] = backLeftHip;
    all[6] = backRightLeg;
    all[7] = backLeftLeg;
}

void GestureController::home()
{
    int testPosition = 90;
    this->frontRightHip->rotateTo(testPosition);
    this->frontLeftHip->rotateTo(testPosition);
    this->frontRightLeg->rotateTo(testPosition);
    this->frontLeftLeg->rotateTo(testPosition);
    this->backRightHip->rotateTo(testPosition);
    this->backLeftHip->rotateTo(testPosition);
    this->backRightLeg->rotateTo(testPosition);
    this->backLeftLeg->rotateTo(testPosition);
}

void GestureController::walk()
{
    int x_amp = 15;
    int z_amp = 20;
    int ap = 20;
    int hi = -10;
    this->frontRightHip->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + ap, 270);
    this->frontLeftHip->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - ap, 270);
    this->frontRightLeg->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 - hi, 270);
    this->frontLeftLeg->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 + hi, 90);
    this->backRightHip->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - ap, 90);
    this->backLeftHip->oscillate(x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + ap, 90);
    this->backRightLeg->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 + hi, 90);
    this->backLeftLeg->oscillate(z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 - hi, 270);
}

void GestureController::update()
{
    for (int i = 0; i < 8; i++)
    {
        all[i]->update();
    }
}

bool GestureController::isDone()
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
