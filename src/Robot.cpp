#include "Robot.h"
#include "Controllers/Display/DisplayController.h"
#include "Hardware/HardwareConfig.h"
#include "Config.h"
#include "logger.h"

/*
   (servo index, pin to attach pwm)
   __________ __________ _________________
  |(3,9)_____)(1,8)      (0,2)(______(2,3)|
  |__|       |left FRONT right|        |__|
             |                |
             |                |
             |                |
   _________ |                | __________
  |(7,7)_____)(5,6)______(4,4)(______(6,5)|
  |__|                                 |__|

*/
// comment below manually setting trim in MiniKame() constructor
#define __LOAD_TRIM_FROM_EEPROM__
#define EEPROM_MAGIC 0xabcd
#define EEPROM_OFFSET 2 // eeprom starting offset to store trim[]

Robot::Robot(
  HAL* hal,
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
  PinNumber backLeftLegServoPin) : 
  currentTime(currentTime)
{
  this->ledMatrixDinPin = ledMatrixDinPin;
  this->ledMatrixClkPin = ledMatrixClkPin;
  this->ledMatrixCsPin = ledMatrixCsPin;
  this->buzzerPin = buzzerPin;
  this->bluetoothRxPin = bluetoothRxPin;
  this->bluetoothTxPin = bluetoothTxPin;

  this->board_pins[FRONT_RIGHT_HIP] = frontRightHipServoPin;
  this->board_pins[FRONT_LEFT_HIP] = frontLeftHipServoPin;
  this->board_pins[FRONT_RIGHT_LEG] = frontRightLegServoPin;
  this->board_pins[FRONT_LEFT_LEG] = frontLeftLegServoPin;
  this->board_pins[BACK_RIGHT_HIP] = backRightHipServoPin;
  this->board_pins[BACK_LEFT_HIP] = backLeftHipServoPin;
  this->board_pins[BACK_RIGHT_LEG] = backRightLegServoPin;
  this->board_pins[BACK_LEFT_LEG] = backLeftLegServoPin;

  this->displayController = new DisplayController(hal, this, this->ledMatrixDinPin, this->ledMatrixClkPin, this->ledMatrixCsPin, LED_MATRIX_FLIP_X);
      
  this->soundController = new SoundController(hal, this, this->buzzerPin);

  this->bodyController = new BodyController(
      hal,
      this,
      this->board_pins[FRONT_RIGHT_HIP],
      this->board_pins[FRONT_LEFT_HIP],
      this->board_pins[FRONT_RIGHT_LEG],
      this->board_pins[FRONT_LEFT_LEG],
      this->board_pins[BACK_RIGHT_HIP],
      this->board_pins[BACK_LEFT_HIP],
      this->board_pins[BACK_RIGHT_LEG],
      this->board_pins[BACK_LEFT_LEG]);


  this->displayActions = new DisplayActions(displayController);

  this->soundActions = new SoundActions(soundController);

  this->movementActions = new MovementActions(bodyController);
  
  this->bluetoothController = new BluetoothController(
      hal,
      this->bluetoothRxPin,
      this->bluetoothTxPin,
      BLUETOOTH_NAME,
      BLUETOOTH_PIN_CODE,
      this->bcodeInputBuffer,
      BCODE_INPUT_BUFFER_SIZE);
  }

BodyController *Robot::getBodyController()
{
  return bodyController;
}

DisplayController *Robot::getDisplayController()
{
  return displayController;
}

SoundController *Robot::getSoundController()
{
  return soundController;
}

DisplayActions *Robot::getDisplayActions()
{
  return displayActions;
}

SoundActions *Robot::getSoundActions()
{
  return soundActions;
}

MovementActions *Robot::getMovementActions()
{
  return movementActions;
}


void Robot::update(unsigned long currentTime)
{
  this->currentTime = currentTime;
  // Update servos states
  this->bodyController->update();

  // Update LED matrix
  this->displayController->update();
  // Update sound controller
  this->soundController->update();
  // Update Bluetooth input
  this->bluetoothController->update();
}

unsigned long Robot::getCurrentTime() {
    return currentTime;
}

