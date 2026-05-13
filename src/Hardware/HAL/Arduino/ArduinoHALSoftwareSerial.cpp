#include "ArduinoHALSoftwareSerial.h"

ArduinoHALSoftwareSerial::ArduinoHALSoftwareSerial(PinNumber rxPin, PinNumber txPin)
    : serial(rxPin, txPin)
{
}

void ArduinoHALSoftwareSerial::begin(unsigned long baudRate)
{
    serial.begin(baudRate);
}

int ArduinoHALSoftwareSerial::available()
{
    return serial.available();
}

int ArduinoHALSoftwareSerial::read()
{
    return serial.read();
}

unsigned int ArduinoHALSoftwareSerial::print(const char* text)
{
    return serial.print(text);
}