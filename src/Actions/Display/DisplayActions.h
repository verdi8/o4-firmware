#pragma once
#include <Arduino.h>
#include "Actions/Actions.h"
#include "Controllers/Display/DisplayController.h"

/**
 * @class Display
 */
class DisplayActions : public Actions {
private:
    DisplayController* displayController; // Pointer to the DisplayController instance that performs the actual display actions

public:
    /**
     * @brief Constructor that initializes the DisplayActions with a DisplayController instance.
     * 
     * @param displayController Pointer to the DisplayController instance.
     */
    DisplayActions(DisplayController* displayController);
    
    /**
     * @brief Plays a wave animation on the display.
     * 
     * @param currentTime The current time in milliseconds.
     */
    void playWaveAnimation(unsigned long currentTime);

};