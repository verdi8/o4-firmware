#pragma once

class Controller {
public:

    /**
     * @brief Updates the state of the GestureController.
     * 
     * @param currentTime The current time in milliseconds.
     */
    virtual void update() = 0;

    /**
     * @brief Checks if the current operation is complete.
     * 
     * @param currentTime The current time in milliseconds.
     * @return true if the operation is complete, false otherwise.
     */
    virtual bool isDone() = 0;

};

