#pragma once

#include "Hardware/HAL/HALSoftwareSerial.h"

/**
 * @class IOUtils
 * @brief Utility class for common I/O helpers.
 */
class IOUtils {
public:
	/**
	 * @brief Reads characters from a serial transport until a stop character,
	 * end of available data, or buffer capacity is reached.
	 *
	 * The stop character is not copied into the destination buffer. The buffer
	 * is always null-terminated when maxSize is greater than 0.
	 *
	 * @param serial The serial transport to read from.
	 * @param buffer The destination buffer.
	 * @param stopChar The character that stops the read.
	 * @param maxSize The total buffer capacity including the null terminator.
	 */
	static void readUntil(HALSoftwareSerial* serial, char* buffer, char stopChar, unsigned int maxSize);
};