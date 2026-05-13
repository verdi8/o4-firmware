#pragma once

#include <map>
#include <utility>

#include "MockTypes.h"
#include "Hardware/HAL/HAL.h"
#include "MockHALSoftwareSerial.h"
#include "MockHALSystem.h"

class MockHAL : public HAL {
public:
    MockHAL();
    ~MockHAL();

    MockHALSystem* getMockHALSystem();
    MockHALSoftwareSerial* getMockHALSoftwareSerial(PinNumber rxPin, PinNumber txPin);
    MockHALSoftwareSerial* getLastMockHALSoftwareSerial();

    HALServo* newServo() override;
    HALTone* newTone(PinNumber buzzerPin) override;
    HALLedControl* newLedControl(PinNumber dataPin, PinNumber clkPin, PinNumber csPin) override;
    HALSystem* newSystem() override;
    HALSoftwareSerial* newSoftwareSerial(PinNumber rxPin, PinNumber txPin) override;
    HALProgramSpaceHelper* newProgramSpaceHelper() override;

private:
    std::map<std::pair<PinNumber, PinNumber>, MockHALSoftwareSerial*> mockHALSoftwareSerials;
    MockHALSoftwareSerial* lastMockHALSoftwareSerial;
    MockHALSystem* mockHALSystem;
};
