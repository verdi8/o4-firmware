#pragma once

/**
 * @class BCodeCommandHandler
 * @brief Interface for handling BCode commands.
 */
class BCodeCommandHandler {
public:

    /**
     * @brief Performs an action based on the given command code.
     * @param code The integer representing the command.
     */
    virtual void performAction(int code) = 0;

};
