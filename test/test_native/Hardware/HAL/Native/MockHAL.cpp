#include "MockHAL.h"

MockHAL::MockHAL()
    : lastMockHALSoftwareSerial(nullptr), mockHALSystem(new MockHALSystem())
{
}

MockHAL::~MockHAL()
{
    for (std::map<std::pair<PinNumber, PinNumber>, MockHALSoftwareSerial*>::iterator it = mockHALSoftwareSerials.begin(); it != mockHALSoftwareSerials.end(); ++it) {
        delete it->second;
    }

    delete mockHALSystem;
}

MockHALSystem* MockHAL::getMockHALSystem()
{
    return mockHALSystem;
}

MockHALSoftwareSerial* MockHAL::getMockHALSoftwareSerial(PinNumber rxPin, PinNumber txPin)
{
    const std::pair<PinNumber, PinNumber> key(rxPin, txPin);
    std::map<std::pair<PinNumber, PinNumber>, MockHALSoftwareSerial*>::iterator it = mockHALSoftwareSerials.find(key);
    if (it == mockHALSoftwareSerials.end()) {
        return nullptr;
    }

    return it->second;
}

MockHALSoftwareSerial* MockHAL::getLastMockHALSoftwareSerial()
{
    return lastMockHALSoftwareSerial;
}

HALServo* MockHAL::newServo()
{
    return nullptr;
}

HALTone* MockHAL::newTone(PinNumber buzzerPin)
{
    (void)buzzerPin;
    return nullptr;
}

HALLedControl* MockHAL::newLedControl(PinNumber dataPin, PinNumber clkPin, PinNumber csPin)
{
    (void)dataPin;
    (void)clkPin;
    (void)csPin;
    return nullptr;
}

HALSystem* MockHAL::newSystem()
{
    return mockHALSystem;
}

HALSoftwareSerial* MockHAL::newSoftwareSerial(PinNumber rxPin, PinNumber txPin)
{
    const std::pair<PinNumber, PinNumber> key(rxPin, txPin);
    std::map<std::pair<PinNumber, PinNumber>, MockHALSoftwareSerial*>::iterator it = mockHALSoftwareSerials.find(key);
    if (it != mockHALSoftwareSerials.end()) {
        lastMockHALSoftwareSerial = it->second;
        return lastMockHALSoftwareSerial;
    }

    lastMockHALSoftwareSerial = new MockHALSoftwareSerial(rxPin, txPin);
    mockHALSoftwareSerials[key] = lastMockHALSoftwareSerial;
    return lastMockHALSoftwareSerial;
}

HALProgramSpaceHelper* MockHAL::newProgramSpaceHelper()
{
    return nullptr;
}
