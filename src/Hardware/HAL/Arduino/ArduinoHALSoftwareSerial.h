#pragma once

#include <SoftwareSerial.h>

#include "../HALSoftwareSerial.h"

/**
 * @brief Arduino-specific HALSoftwareSerial implementation backed by SoftwareSerial.
 */
class ArduinoHALSoftwareSerial : public HALSoftwareSerial {
public:
    /**
     * @brief Constructs a software serial transport on the provided pins.
     *
     * @param rxPin The receive pin number.
     * @param txPin The transmit pin number.
     */
    ArduinoHALSoftwareSerial(PinNumber rxPin, PinNumber txPin);

    void begin(unsigned long baudRate) override;
    int available() override;
    int read() override;
    unsigned int print(const char* text) override;

private:
    SoftwareSerial serial;
};