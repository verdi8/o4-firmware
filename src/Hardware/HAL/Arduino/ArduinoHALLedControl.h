#pragma once
#include "Hardware/HAL/HALLedControl.h"
#include <LedControl.h>

class ArduinoHALLedControl : public HALLedControl {
public:
    ArduinoHALLedControl(uint8_t dataPin, uint8_t clkPin, uint8_t csPin)
    : ledControl(dataPin, clkPin, csPin, 1){
    }

    void setIntensity(uint8_t deviceIndex, uint8_t intensity) override;

    void clearDisplay(uint8_t deviceIndex) override;

    void setColumn(uint8_t deviceIndex, uint8_t colIndex, uint8_t value) override;

    void shutdown(uint8_t deviceIndex, bool status) override;

private:
    LedControl ledControl; 
};

