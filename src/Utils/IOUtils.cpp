#include "IOUtils.h"

void IOUtils::readUntil(HALSoftwareSerial* serial, char* buffer, char stopChar, unsigned int maxSize) {
	if (buffer == nullptr || maxSize == 0) {
		return;
	}

	buffer[0] = '\0';

	if (serial == nullptr) {
		return;
	}

	unsigned int length = 0;
	while (length < maxSize - 1) {
		int value = serial->read();
		if (value < 0) {
			break;
		}

		if (static_cast<char>(value) == stopChar) {
			break;
		}

		buffer[length++] = static_cast<char>(value);
	}

	buffer[length] = '\0';
}
