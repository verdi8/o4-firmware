#include "ArduinoHALProgramSpaceHelper.h"

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
