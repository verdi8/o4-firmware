#pragma once

#include <deque>
#include <string>

#include "Hardware/HAL/HALSoftwareSerial.h"

class MockHALSoftwareSerial : public HALSoftwareSerial {
public:
    MockHALSoftwareSerial(PinNumber rxPin, PinNumber txPin);

    void begin(unsigned long baudRate) override;
    int available() override;
    int read() override;
    unsigned int print(const char* text) override;

    unsigned long getBaudRate() const;
    PinNumber getRxPin() const;
    PinNumber getTxPin() const;

    void reset();
    void pushInputData(const char* text);
    void pushInputData(const std::string& text);
    std::string getOutputData() const;

private:
    unsigned long baudRate;
    std::deque<char> inputData;
    std::string outputData;
    PinNumber rxPin;
    PinNumber txPin;
};