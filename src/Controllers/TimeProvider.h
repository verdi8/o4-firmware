#pragma once

/**
 * @class TimeProvider
 * @brief Interface for retrieving the current time.
 *
 * It provides the same time for all the controllers of the 
 */
class TimeProvider
{
public:
    virtual ~TimeProvider() = default;

    /**
     * @brief Retrieves the current time.
     * @return The current time as an unsigned long.
     *
     * This method returns the current time, which can be used for
     * time-sensitive operations or logging purposes.
     */
    virtual unsigned long getCurrentTime() = 0;
};