#pragma once

class Controller {
public:

    /**
     * @brief Updates the state of the BodyController.
     */
    virtual void update() = 0;

    /**
     * @brief Checks if the current operation is complete.

     * @return true if the operation is complete, false otherwise.
     */
    virtual bool isDone() = 0;

};

