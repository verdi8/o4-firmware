#pragma once

#include "Hardware/HAL/HALSystem.h"

class MockHALSystem : public HALSystem {
public:
    MockHALSystem()
        : currentMillis(0), currentMillisIncrement(0)
    {
    }

    unsigned long millis() override
    {
        const unsigned long currentValue = currentMillis;
        currentMillis += currentMillisIncrement;
        return currentValue;
    }

    void delay(unsigned long durationMs) override { (void)durationMs; }

    void setMillis(unsigned long millis)
    {
        currentMillis = millis;
    }

    void setCurrentMillisIncrement(unsigned long increment)
    {
        currentMillisIncrement = increment;
    }

private:
    unsigned long currentMillis;
    unsigned long currentMillisIncrement;
};
