#include "ArduinoHALProgramSpaceHelper.h"
#include <cstring>

/**
 * @brief Reads a byte from program memory.
 * @param address Pointer to the address in program memory.
 * @return The byte value read from the specified address.
 */
inline byte ArduinoHALProgramSpaceHelper::readByte(const void* address) const {
    return pgm_read_byte(address);
}

/**
 * @brief Reads a word (2 bytes) from program memory.
 * @param address Pointer to the address in program memory.
 * @return The word value read from the specified address.
 */
inline word ArduinoHALProgramSpaceHelper::readWord(const void* address) const {
    return pgm_read_word(address);
}

/**
 * @brief Copies a block of data from program memory into RAM.
 * @param destination Pointer to the destination buffer in RAM.
 * @param source Pointer to the source address in program memory.
 * @param size Number of bytes to copy.
 */
inline void ArduinoHALProgramSpaceHelper::memcpy(void* destination, const void* source, size_t size) const {
    memcpy_P(destination, source, size);
}
