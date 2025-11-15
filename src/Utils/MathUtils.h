#pragma once

/**
 * @class MathUtils
 * @brief Utility class for common mathematical operations.
 */
class MathUtils {
public:
    /**
     * @brief The mathematical constant PI.
     */
    static constexpr double PI = 3.14159265358979323846;

    /**
     * @brief Returns the smaller of two unsigned integers.
     * @param a First unsigned integer.
     * @param b Second unsigned integer.
     * @return The smaller of the two values.
     */
    static unsigned int _min(unsigned int a, unsigned int b);

    /**
     * @brief Returns the larger of two unsigned integers.
     * @param a First unsigned integer.
     * @param b Second unsigned integer.
     * @return The larger of the two values.
     */
    static unsigned int _max(unsigned int a, unsigned int b);

    /**
     * @brief Converts an angle from degrees to radians.
     * @param degrees Angle in degrees.
     * @return Angle in radians.
     */
    static double deg2rad(double degrees);

    /**
     * @brief Computes the sine of a value in radians.
     * @param value Angle in radians.
     * @return Sine of the angle.
     */
    static double sin(double value);

};
