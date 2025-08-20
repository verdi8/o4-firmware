#include "GestureController.h"

GestureController::GestureController(
            int frontRightHipPin,
        int frontLeftHipPin,
        int frontRightLegPin,
        int frontLeftLegPin,
        int backRightHipPin,
        int backLeftHipPin,
        int backRightLegPin,
        int backLeftLegPin) {
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