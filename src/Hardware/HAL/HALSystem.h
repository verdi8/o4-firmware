#pragma once

/**
 * @brief Abstract interface for platform-level system functions.
 */
class HALSystem {
public:
    /**
     * @brief Retrieves the number of milliseconds since startup.
     *
     * @return The current uptime in milliseconds.
     */
    virtual unsigned long millis() = 0;

    /**
     * @brief Delays execution for the provided duration.
     *
     * @param durationMs Delay duration in milliseconds.
     */
    virtual void delay(unsigned long durationMs) = 0;
};