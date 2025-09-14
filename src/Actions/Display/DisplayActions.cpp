#include "DisplayActions.h"
#include "Library/Animations.h" // Include the Animations library
#include "Controllers/Display/DisplayController.h"


/**
 * @brief Constructs a DisplayActions with the specified DisplayController instance.
 * 
 * @param displayController Pointer to the DisplayController instance.
 */
DisplayActions::DisplayActions(DisplayController* displayController) : displayController(displayController) {}

/**
 * @brief Plays a wave animation on the display.
 * 
 * @param currentTime The current time in milliseconds.
 */
void DisplayActions::playWaveAnimation() {
    displayController->playAnimation((FrameSet*)&WAVE_FRAMESET, 300, 0); // Play the wave animation with 100 ms frame duration and infinite repeat
}
