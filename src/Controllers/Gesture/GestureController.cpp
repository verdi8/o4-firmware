#include "GestureController.h"

// Behaviour parameters
#define DEFAULT_OSCILLIATION_PERIOD 1000 // in milliseconds

GestureController::GestureController(
            PIN_NUMBER frontRightHipPin,
        PIN_NUMBER frontLeftHipPin,
        PIN_NUMBER frontRightLegPin,
        PIN_NUMBER frontLeftLegPin,
        PIN_NUMBER backRightHipPin,
        PIN_NUMBER backLeftHipPin,
        PIN_NUMBER backRightLegPin,
        PIN_NUMBER backLeftLegPin) {
    frontRightHip = new ServoController(frontRightHipPin);
    frontLeftHip = new ServoController(frontLeftHipPin);
    frontRightLeg = new ServoController(frontRightLegPin);
    frontLeftLeg = new ServoController(frontLeftLegPin);
    backRightHip = new ServoController(backRightHipPin);
    backLeftHip = new ServoController(backLeftHipPin);
    backRightLeg = new ServoController(backRightLegPin);
    backLeftLeg = new ServoController(backLeftLegPin);
    all[0] = frontRightHip;
    all[1] = frontLeftHip;
    all[2] = frontRightLeg;
    all[3] = frontLeftLeg;
    all[4] = backRightHip;
    all[5] = backLeftHip;
    all[6] = backRightLeg;
    all[7] = backLeftLeg;
}


void GestureController::home() {
  unsigned long currentTime = millis();
  int testPosition = 90;
  this->frontRightHip->rotateTo(currentTime, testPosition);
  this->frontLeftHip->rotateTo(currentTime, testPosition);
  this->frontRightLeg->rotateTo(currentTime, testPosition);
  this->frontLeftLeg->rotateTo(currentTime, testPosition);
  this->backRightHip->rotateTo(currentTime, testPosition);
  this->backLeftHip->rotateTo(currentTime, testPosition);
  this->backRightLeg->rotateTo(currentTime, testPosition);
  this->backLeftLeg->rotateTo(currentTime, testPosition);
}

void GestureController::walk() {
 int x_amp = 15;
  int z_amp = 20;
  int ap = 20;
  int hi = -10;
  unsigned long currentTime = millis();
  this->frontRightHip->oscillate(currentTime, x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + ap, 270);
  this->frontLeftHip->oscillate(currentTime, x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - ap, 270);
  this->frontRightLeg->oscillate(currentTime, z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 - hi, 270);
  this->frontLeftLeg->oscillate(currentTime, z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 + hi, 90);
  this->backRightHip->oscillate(currentTime, x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 - ap, 90);
  this->backLeftHip->oscillate(currentTime, x_amp, DEFAULT_OSCILLIATION_PERIOD, 90 + ap, 90);
  this->backRightLeg->oscillate(currentTime, z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 + hi, 90);
  this->backLeftLeg->oscillate(currentTime, z_amp, DEFAULT_OSCILLIATION_PERIOD / 2, 90 - hi, 270);
}





void GestureController::update(unsigned long currentTime) {
    for (int i = 0; i < 8; i++) {
        all[i]->update(currentTime);
    }
}

bool GestureController::isDone(unsigned long currentTime) {
    for (int i = 0; i < 8; i++) {
        if (!all[i]->isDone(currentTime)) {
            return false;
        }
    }
    return true;
}
