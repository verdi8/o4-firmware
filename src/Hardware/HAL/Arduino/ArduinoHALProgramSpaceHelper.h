#pragma once

#include <Arduino.h>
#include "../HALProgramSpaceHelper.h"

/**
 * @brief Arduino-specific implementation of the HALProgramSpace interface.
 * Provides methods to read data from program memory using Arduino's PROGMEM utilities.
 */
class ArduinoHALProgramSpaceHelper : public HALProgramSpaceHelper {
public:
    /**
     * @brief Reads a byte from program memory.
     * @param address Pointer to the address in program memory.
     * @return The byte value read from the specified address.
     */
    byte readByte(const void* address) const override;

    /**
     * @brief Reads a word (2 bytes) from program memory.
     * @param address Pointer to the address in program memory.
     * @return The word value read from the specified address.
     */
    word readWord(const void* address) const override;

    /**
     * @brief Copies a block of data from program memory into RAM.
     * @param destination Pointer to the destination buffer in RAM.
     * @param source Pointer to the source address in program memory.
     * @param size Number of bytes to copy.
     */
    void memcpy(void* destination, const void* source, size_t size) const override;


};

