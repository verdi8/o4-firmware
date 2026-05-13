#pragma once

#include "Hardware/HAL/HAL.h"
#include "Hardware/HAL/HALSoftwareSerial.h"
#include "Hardware/HAL/HALSystem.h"
#include "Hardware/HAL/HALTypes.h"

#include "BluetoothATDevice.h"

/**
 * @brief HC-06 implementation of BluetoothATDevice.
 *
 * This class sends HC-06 AT commands over a HALSoftwareSerial transport.
 */
class HC06BluetoothATDevice : public BluetoothATDevice {
public:
    /**
      * @brief Creates a HC-06 AT device using a software serial link created by the HAL.
      *
      * @param hal The HAL used to create the serial transport.
      * @param rxPin The receive pin number.
      * @param txPin The transmit pin number.
      */
    HC06BluetoothATDevice(HAL* hal, PinNumber rxPin, PinNumber txPin);

    bool setName(const char* name) override;
    bool setBaudrate(unsigned long baudRate) override;
    bool setPinCode(const char* pinCode) override;

    HALSoftwareSerial* getSoftwareSerial();

private:
    static constexpr unsigned int COMMAND_BUFFER_SIZE = 32;
    static constexpr unsigned int RESPONSE_BUFFER_SIZE = 32;
    static constexpr unsigned long RESPONSE_TIMEOUT_MS = 1000;

    HALSystem* system;
    HALSoftwareSerial* serial;

    bool sendCommandAndExpect(const char* command, const char* expectedResponse);
    bool readResponseContains(const char* expectedResponse);
    const char* getBaudrateCode(unsigned long baudRate);
};