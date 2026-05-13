#include "HC06BluetoothATDevice.h"
#include "logger.h"

#include <string.h>

namespace {
bool buildCommand(char* destination, unsigned int destinationSize, const char* prefix, const char* suffix)
{
    if (destination == nullptr || destinationSize == 0 || prefix == nullptr || suffix == nullptr) {
        return false;
    }

    const size_t prefixLength = strlen(prefix);
    const size_t suffixLength = strlen(suffix);
    if (prefixLength + suffixLength >= destinationSize) {
        return false;
    }

    memcpy(destination, prefix, prefixLength);
    memcpy(destination + prefixLength, suffix, suffixLength);
    destination[prefixLength + suffixLength] = '\0';
    return true;
}

const char* getBauderateAsString(unsigned long baudRate)
{
    switch (baudRate) {
    case 1200:
        return "1200";
    case 2400:
        return "2400";
    case 4800:
        return "4800";
    case 9600:
        return "9600";
    case 19200:
        return "19200";
    case 38400:
        return "38400";
    case 57600:
        return "57600";
    case 115200:
        return "115200";
    default:
        return nullptr;
    }
}
}

HC06BluetoothATDevice::HC06BluetoothATDevice(HAL* hal, PinNumber rxPin, PinNumber txPin)
    : system(hal->newSystem()), serial(hal->newSoftwareSerial(rxPin, txPin))
{
    serial->begin(9600); // HC-06 default baud rate
}

HALSoftwareSerial* HC06BluetoothATDevice::getSoftwareSerial()
{
    return serial;
}

bool HC06BluetoothATDevice::setName(const char* name)
{
    char command[COMMAND_BUFFER_SIZE];
    if (!buildCommand(command, sizeof(command), "AT+NAME", name)) {
        return false;
    }

    return sendCommandAndExpect(command, "OK");
}

bool HC06BluetoothATDevice::setBaudrate(unsigned long baudRate)
{
    const char* baudrateCode = getBaudrateCode(baudRate);
    if (baudrateCode == nullptr) {
        return false;
    }

    char command[COMMAND_BUFFER_SIZE];
    if (!buildCommand(command, sizeof(command), "AT+BAUD", baudrateCode)) {
        return false;
    }

    const char* baudRateText = getBauderateAsString(baudRate);
    if (baudRateText == nullptr) {
        return false;
    }

    char expectedResponse[16];
    if (!buildCommand(expectedResponse, sizeof(expectedResponse), "OK", baudRateText)) {
        return false;
    }

    return sendCommandAndExpect(command, expectedResponse);
}

bool HC06BluetoothATDevice::setPinCode(const char* pinCode)
{
    char command[COMMAND_BUFFER_SIZE];
    if (!buildCommand(command, sizeof(command), "AT+PIN", pinCode)) {
        return false;
    }

    return sendCommandAndExpect(command, "OKsetPIN");
}

bool HC06BluetoothATDevice::sendCommandAndExpect(const char* command, const char* expectedResponse)
{
    DEBUG(F("Sending command:"));
    DEBUG(command);

    if (serial->print(command) == 0) {
        DEBUG(F("Failed to send command"));
        return false;
    }

    return readResponseContains(expectedResponse);
}

bool HC06BluetoothATDevice::readResponseContains(const char* expectedResponse)
{
    DEBUG(F("Waiting for response:"));
    DEBUG(expectedResponse);

    char response[RESPONSE_BUFFER_SIZE];
    unsigned int responseLength = 0;

    memset(response, 0, RESPONSE_BUFFER_SIZE);

    const unsigned long startTime = system->millis();
    while (system->millis() - startTime < RESPONSE_TIMEOUT_MS) {
        if (serial->available() <= 0) {
            continue;
        }

        int value = serial->read();
        if (value < 0) {
            continue;
        }

        if (responseLength < RESPONSE_BUFFER_SIZE - 1) {
            response[responseLength++] = static_cast<char>(value);
            response[responseLength] = '\0';
        }

        if (strstr(response, expectedResponse) != nullptr) {
            DEBUG(F("Expected response received"));
            return true;
        }
    }

    DEBUG(F("Did not receive expected response within attempts"));   
    return false;
}

const char* HC06BluetoothATDevice::getBaudrateCode(unsigned long baudRate)
{
    switch (baudRate) {
    case 1200:
        return "1";
    case 2400:
        return "2";
    case 4800:
        return "3";
    case 9600:
        return "4";
    case 19200:
        return "5";
    case 38400:
        return "6";
    case 57600:
        return "7";
    case 115200:
        return "8";
    default:
        return nullptr;
    }
}