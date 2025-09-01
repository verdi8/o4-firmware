#include <Arduino.h>

#ifndef HARDWARE_H
#define HARDWARE_H

// Rédefinition of PinNumber type
typedef uint8_t PinNumber;


//
// Led Matrix
//
#define LED_MATRIX_DIN          A1
#define LED_MATRIX_CS           A2
#define LED_MATRIX_CLK          A3
#define LED_MATRIX_INTENSITY    15 // 0-15
#define LED_MATRIX_FLIP_X       true

//
// Buzzer
//
constexpr PinNumber PIN_BUZZER = 13; // Pin connected to the buzzer

//
// Servo pins
//
#define FRONT_RIGHT_HIP_SERVO_PIN     2
#define FRONT_LEFT_HIP_SERVO_PIN      6
#define FRONT_RIGHT_LEG_SERVO_PIN     3
#define FRONT_LEFT_LEG_SERVO_PIN      4
#define BACK_RIGHT_HIP_SERVO_PIN      7
#define BACK_LEFT_HIP_SERVO_PIN       9
#define BACK_RIGHT_LEG_SERVO_PIN      5
#define BACK_LEFT_LEG_SERVO_PIN       8


#endif
