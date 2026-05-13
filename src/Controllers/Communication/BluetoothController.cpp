#include "BluetoothController.h"
#include "logger.h"
#include "Utils/IOUtils.h"
#include "Config.h"

BluetoothController::BluetoothController(HAL* hal, PinNumber rxPin, PinNumber txPin, const char* name, const char* pinCode, char* buffer, unsigned int bufferSize)
    : initialized(false), buffer(buffer), bufferSize(bufferSize), currentBufferPosition(0), lineCompleted(false), bluetoothATDevice(nullptr)
{
    INFO(F("Initializing bluetooth controller"));

    bluetoothATDevice = new HC06BluetoothATDevice(hal, rxPin, txPin);

    INFO_(F("Setting Bluetooth name to "), name);
    if (!bluetoothATDevice->setName(name)) {
        ERROR(F("Failed to set Bluetooth name"));
        return;
    }
    INFO(F("Setting Bluetooth baud rate to 9600"));
    if (!bluetoothATDevice->setBaudrate(9600)) {
        ERROR(F("Failed to set Bluetooth baud rate"));
        return;
    }
    INFO_(F("Setting Bluetooth PIN to "), pinCode);
    if (!bluetoothATDevice->setPinCode(pinCode)) {
        ERROR(F("Failed to set Bluetooth PIN"));
        return;
    }

    initialized = true;
    INFO(F("BluetoothController initialized"));
}

void BluetoothController::update()
{
    if (!initialized) {
        return;
    }

    lineCompleted = false;

    HALSoftwareSerial* softwareSerial = bluetoothATDevice->getSoftwareSerial();

    unsigned int bytesRead = 0;
    while (softwareSerial->available() > 0 && bytesRead < BLUETOOTH_READ_CHUNK_SIZE && !lineCompleted) {
        int value = softwareSerial->read();
        if (value < 0) {
            continue;
        }

        char receivedChar = static_cast<char>(value);
        if (receivedChar == '\r') {
            continue;
        }

        if (receivedChar == '\n') {
            buffer[currentBufferPosition] = '\0';
            markLineCompleted();
            return;
        }

        if (currentBufferPosition < bufferSize - 1) {
            buffer[currentBufferPosition++] = receivedChar;
            buffer[currentBufferPosition] = '\0';
        } else {
            buffer[bufferSize - 1] = '\0';
            markLineCompleted();
            return;
        }

        ++bytesRead;
    }
}

void BluetoothController::markLineCompleted() {
    lineCompleted = true;
    currentBufferPosition = 0;
}

bool BluetoothController::isDone()
{
    return initialized && lineCompleted;
}