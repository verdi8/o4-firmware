#pragma once

#include "HALTypes.h"

/**
 * @brief Interface for accessing data stored in program memory.
 */
class HALProgramSpaceHelper {
public:
    /**
     * @brief Reads a byte from program memory.
     * @param address Pointer to the address in program memory.
     * @return The byte value read from the specified address.
     */
    virtual byte readByte(const void* address) const = 0;

    /**
     * @brief Reads a word (2 bytes) from program memory.
     * @param address Pointer to the address in program memory.
     * @return The word value read from the specified address.
     */
    virtual word readWord(const void* address) const = 0;

    /**
     * @brief Copies a block of data from program memory into RAM.
     * @param destination Pointer to the destination buffer in RAM.
     * @param source Pointer to the source address in program memory.
     * @param size Number of bytes to copy.
     */
    virtual void memcpy(void* destination, const void* source, size_t size) const = 0;

};
