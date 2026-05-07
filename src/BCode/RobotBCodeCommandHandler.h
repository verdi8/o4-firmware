#pragma once

#include <b-code-interpreter.h>

/**
 * @class RobotBCodeCommandHandler
 * @brief Implementation of BCodeCommandHandler for robot-specific commands.
 */
class RobotBCodeCommandHandler : public bcode::CommandHandler {
public:
    /**
     * @brief Performs an action based on the given command code.
     * @param code The integer representing the command.
     */
    unsigned int performAction(int code) override;

};
