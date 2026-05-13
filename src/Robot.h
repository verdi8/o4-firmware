#pragma once

#include <b-code-interpreter.h>
#include "Config.h"
#include "Controllers/Display/DisplayController.h"
#include "Controllers/Body/BodyController.h"
#include "Controllers/Sound/SoundController.h"
#include "Actions/Display/DisplayActions.h"
#include "Actions/Sound/SoundActions.h"
#include "Actions/Movement/MovementActions.h"
#include "Controllers/TimeProvider.h"
#include "Controllers/Communication/BluetoothController.h"
#include "Hardware/HAL/HAL.h"

// Servo indexes
#define FRONT_RIGHT_HIP   0
#define FRONT_LEFT_HIP    1
#define FRONT_RIGHT_LEG   2
#define FRONT_LEFT_LEG    3
#define BACK_RIGHT_HIP    4
#define BACK_LEFT_HIP     5
#define BACK_RIGHT_LEG    6
#define BACK_LEFT_LEG     7


#define OttoHappy     0
#define OttoSuperHappy  1
#define OttoSad     2
#define OttoSleeping  3
#define OttoFart    4
#define OttoConfused  5
#define OttoLove    6
#define OttoAngry     7
#define OttoFretful   8
#define OttoMagic     9
#define OttoWave    10
#define OttoVictory   11
#define OttoFail    12

//*** MOUTH ANIMATIONS***
#define littleUuh   0
#define dreamMouth    1   
#define adivinawi   2
#define wave      3


//#define PIN_NoiseSensor A6
extern "C" void pause(int);

class Robot : public TimeProvider {
  private:
    // Controllers of physical parts
    DisplayController* displayController;
    SoundController* soundController;
    BodyController* bodyController;
    BluetoothController* bluetoothController;

    // Sets of actions that 
    DisplayActions* displayActions;
    SoundActions* soundActions; 
    MovementActions* movementActions;

    unsigned long currentTime; // Variable to store the current time

    // Servo servo[8];
    PinNumber ledMatrixDinPin;
    PinNumber ledMatrixClkPin;
    PinNumber ledMatrixCsPin;
    PinNumber buzzerPin;
    PinNumber bluetoothRxPin;
    PinNumber bluetoothTxPin;
    int board_pins[8];
    int trim[8]; //deviation servo offset
    //unsigned long _init_time;
    // unsigned long _final_time;

    char bcodeInputBuffer[BCODE_INPUT_BUFFER_SIZE];

  public:
    Robot(
      HAL *hal,
      unsigned long currentTime,
      PinNumber ledMatrixDinPin,
      PinNumber ledMatrixClkPin,
      PinNumber ledMatrixCsPin,
      PinNumber buzzerPin,
      PinNumber bluetoothRxPin,
      PinNumber bluetoothTxPin,
      PinNumber frontRightHipServoPin,
      PinNumber frontLeftHipServoPin,
      PinNumber frontRightLegServoPin,
      PinNumber frontLeftLegServoPin,
      PinNumber backRightHipServoPin,
      PinNumber backLeftHipServoPin,
      PinNumber backRightLegServoPin,
      PinNumber backLeftLegServoPin
    );

    DisplayActions *getDisplayActions();
    SoundActions* getSoundActions();

    BodyController* getBodyController();
    DisplayController* getDisplayController();
    SoundController* getSoundController();
    MovementActions* getMovementActions();
    void setTrim(int index, int value) {
      trim[index] = value;
    }
    

    void update(unsigned long currentTime);

    /**
     * @brief Retrieves the current time.
     * @return The current time as an unsigned long.
     */
    unsigned long getCurrentTime() override;
   
};
