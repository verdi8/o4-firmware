#pragma once

#include "Actions/Actions.h"
#include "Controllers/Body/BodyController.h"

/**
 * @class MovementActions
 * @brief Defines movement-related actions within the system.
 */
class MovementActions : public Actions {
private:
    BodyController* bodyController; // Pointer to the BodyController instance that performs the actual movement actions

public:
    /**
     * @brief Constructor for MovementActions.
     */
    MovementActions(BodyController* bodyController);

    /**
     * @brief Moves the robot to its home position.
     */
    void home();

    /**
     * @brief Makes the robot walk using the configured servo controllers.
     */
    void walk();

};
