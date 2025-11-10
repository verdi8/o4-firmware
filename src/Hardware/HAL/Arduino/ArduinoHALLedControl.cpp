#include "ArduinoHALLedControl.h"

/**
 * @brief Set the intensity of the LED matrix.
 * 
 * @param deviceIndex The index of the LED matrix device.
 * @param intensity The intensity level (0-15).
 */
void ArduinoHALLedControl::setIntensity(uint8_t deviceIndex, uint8_t intensity) {
    ledControl.setIntensity(deviceIndex, intensity);
}

/**
 * @brief Clear the display of the LED matrix.
 * 
 * @param deviceIndex The index of the LED matrix device.
 */
void ArduinoHALLedControl::clearDisplay(uint8_t deviceIndex) {
    ledControl.clearDisplay(deviceIndex);
}

/**
 * @brief Set a column in the LED matrix.
 * 
 * @param deviceIndex The index of the LED matrix device.
 * @param colIndex The column index (0-7).
 * @param value The value to set for the column.
 */
void ArduinoHALLedControl::setColumn(uint8_t deviceIndex, uint8_t colIndex, uint8_t value) {
    ledControl.setColumn(deviceIndex, colIndex, value);
}

/**
 * @brief Shutdown or wake up the LED matrix.
 * 
 * @param deviceIndex The index of the LED matrix device.
 * @param status true to shutdown, false to wake up.
 */
void ArduinoHALLedControl::shutdown(uint8_t deviceIndex, bool status) {
    ledControl.shutdown(deviceIndex, status);
}

