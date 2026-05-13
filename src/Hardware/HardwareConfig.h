#pragma once

#if defined(ARDUINO)

#include "Hardware/HAL/HAL.h"

//
// Led Matrix
//
constexpr PinNumber     LED_MATRIX_DIN          = A1;
constexpr PinNumber     LED_MATRIX_CS           = A2;
constexpr PinNumber     LED_MATRIX_CLK          = A3;

//
// Buzzer
//
constexpr PinNumber     PIN_BUZZER              = 13; // Pin connected to the buzzer

//
// Bluetooth
//
constexpr PinNumber     BLUETOOTH_RX_PIN            = 10;               // Pin connected to Bluetooth module RX
constexpr PinNumber     BLUETOOTH_TX_PIN            = 11;               // Pin connected to Bluetooth module TX

//
// Servo pins
//
constexpr PinNumber     FRONT_RIGHT_HIP_SERVO_PIN   = 2;
constexpr PinNumber     FRONT_LEFT_HIP_SERVO_PIN    = 4;
constexpr PinNumber     FRONT_RIGHT_LEG_SERVO_PIN   = 3;
constexpr PinNumber     FRONT_LEFT_LEG_SERVO_PIN    = 5;
constexpr PinNumber     BACK_RIGHT_HIP_SERVO_PIN    = 6;
constexpr PinNumber     BACK_LEFT_HIP_SERVO_PIN     = 8;
constexpr PinNumber     BACK_RIGHT_LEG_SERVO_PIN    = 7;
constexpr PinNumber     BACK_LEFT_LEG_SERVO_PIN     = 9;

#endif
