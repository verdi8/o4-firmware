#include "MathUtils.h"
#include <math.h>

/**
 * @brief Returns the smaller of two unsigned integers.
 * @param a First unsigned integer.
 * @param b Second unsigned integer.
 * @return The smaller of the two values.
 */
unsigned int MathUtils::_min(unsigned int a, unsigned int b) {
    return (a < b) ? a : b;
}

/**
 * @brief Returns the larger of two unsigned integers.
 * @param a First unsigned integer.
 * @param b Second unsigned integer.
 * @return The larger of the two values.
 */
unsigned int MathUtils::_max(unsigned int a, unsigned int b) {
    return (a > b) ? a : b;
}

/**
 * @brief Converts an angle from degrees to radians.
 * @param degrees Angle in degrees.
 * @return Angle in radians.
 */
double MathUtils::deg2rad(double degrees) {
    return degrees * (MathUtils::PI / 180.0);
}

/**
 * @brief Computes the sine of a value in radians.
 * @param value Angle in radians.
 * @return Sine of the angle.
 */
double MathUtils::sin(double value) {
    return ::sin(value);
}


