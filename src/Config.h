#pragma once

#include "Hardware/HAL/HAL.h"

//
// Led Matrix
//
constexpr int           LED_MATRIX_INTENSITY    = 15; // 0-15
constexpr bool          LED_MATRIX_FLIP_X       = true;

//
// Buzzer
//

//
// Bluetooth
//
constexpr const char*   BLUETOOTH_NAME              = "O4-ROBOT";       // Bluetooth device name
constexpr const char*   BLUETOOTH_PIN_CODE          = "0000";           // Bluetooth pairing PIN
constexpr unsigned long BLUETOOTH_READ_CHUNK_SIZE   = 10;               // Number of bytes to read each cycle

//
// B-CODE
//
constexpr unsigned int  BCODE_INPUT_BUFFER_SIZE     = 64;               // Maximum size of a received b-code line
