#pragma once

#include "HALTypes.h"

/**
 * @brief Abstract interface for SoftwareSerial-style communication.
 *
 * This interface provides the minimal text-based serial operations needed by
 * communication-oriented controllers while keeping the transport
 * implementation platform-specific.
 */
class HALSoftwareSerial {
public:
    /**
     * @brief Initializes the serial transport with the provided baud rate.
     *
     * @param baudRate The baud rate to use.
     */
    virtual void begin(unsigned long baudRate) = 0;

    /**
     * @brief Returns the number of bytes available for reading.
     *
     * @return The number of bytes available.
     */
    virtual int available() = 0;

    /**
     * @brief Reads the next byte from the serial transport.
     *
     * @return The next byte value, or -1 if none is available.
     */
    virtual int read() = 0;

    /**
     * @brief Writes a null-terminated string to the serial transport.
     *
     * @param text The text to write.
     * @return Number of bytes written.
     */
    virtual unsigned int print(const char* text) = 0;
};