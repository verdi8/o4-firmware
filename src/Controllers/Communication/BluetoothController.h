#pragma once

#include "BluetoothController.h"
#include "Controllers/Communication/Device/HC06BluetoothATDevice.h"
#include "Controllers/Controller.h"
#include "Hardware/HAL/HAL.h"
#include "Hardware/HAL/HALTypes.h"

#include <b-code-interpreter.h>

class BluetoothController : public Controller
{
private:
    bool initialized;
    char* buffer;
    unsigned int bufferSize;
    unsigned int currentBufferPosition;
    bool lineCompleted;
    HC06BluetoothATDevice* bluetoothATDevice;

    void markLineCompleted();

public:
    BluetoothController(HAL* hal, PinNumber rxPin, PinNumber txPin, const char* name, const char* pinCode, char* buffer, unsigned int bufferSize);

    void update() override;
    bool isDone() override;
};