#include "MockHALSoftwareSerial.h"

#include <cstring>

MockHALSoftwareSerial::MockHALSoftwareSerial(PinNumber rxPin, PinNumber txPin)
    : baudRate(0), rxPin(rxPin), txPin(txPin)
{
}

void MockHALSoftwareSerial::begin(unsigned long initialBaudRate)
{
    baudRate = initialBaudRate;
}

int MockHALSoftwareSerial::available()
{
    return static_cast<int>(inputData.size());
}

int MockHALSoftwareSerial::read()
{
    if (inputData.empty()) {
        return -1;
    }

    const char value = inputData.front();
    inputData.pop_front();
    return static_cast<unsigned char>(value);
}

unsigned int MockHALSoftwareSerial::print(const char* text)
{
    if (text == nullptr) {
        return 0;
    }

    outputData += text;
    return static_cast<unsigned int>(std::strlen(text));
}

unsigned long MockHALSoftwareSerial::getBaudRate() const
{
    return baudRate;
}

PinNumber MockHALSoftwareSerial::getRxPin() const
{
    return rxPin;
}

PinNumber MockHALSoftwareSerial::getTxPin() const
{
    return txPin;
}

void MockHALSoftwareSerial::reset()
{
    inputData.clear();
    outputData.clear();
}

void MockHALSoftwareSerial::pushInputData(const char* text)
{
    if (text == nullptr) {
        return;
    }

    for (size_t i = 0; i < std::strlen(text); ++i) {
        inputData.push_back(text[i]);
    }
}

void MockHALSoftwareSerial::pushInputData(const std::string& text)
{
    for (size_t i = 0; i < text.size(); ++i) {
        inputData.push_back(text[i]);
    }
}

std::string MockHALSoftwareSerial::getOutputData() const
{
    return outputData;
}
