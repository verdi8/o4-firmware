#pragma once

#include <Config.h>

/**
 * @brief Abstract interface for LED matrix control.
 * 
 * This interface provides methods to control an LED matrix, such as setting columns,
 * clearing the display, and adjusting intensity.
 */
class HALLedControl {
public:

    /**
     * @brief Set the intensity of the LED matrix.
     * 
     * @param deviceIndex The index of the LED matrix device.
     * @param intensity The intensity level (0-15).
     */
    virtual void setIntensity(uint8_t deviceIndex, uint8_t intensity) = 0;

    /**
     * @brief Clear the display of the LED matrix.
     * 
     * @param deviceIndex The index of the LED matrix device.
     */
    virtual void clearDisplay(uint8_t deviceIndex) = 0;

    /**
     * @brief Set a column in the LED matrix.
     * 
     * @param deviceIndex The index of the LED matrix device.
     * @param colIndex The column index (0-7).
     * @param value The value to set for the column.
     */
    virtual void setColumn(uint8_t deviceIndex, uint8_t colIndex, uint8_t value) = 0;

    /**
     * @brief Shutdown or wake up the LED matrix.
     * 
     * @param deviceIndex The index of the LED matrix device.
     * @param status true to shutdown, false to wake up.
     */
    virtual void shutdown(uint8_t deviceIndex, bool status) = 0;

private:
    uint8_t dataPin;
    uint8_t clkPin;
    uint8_t csPin;
};
