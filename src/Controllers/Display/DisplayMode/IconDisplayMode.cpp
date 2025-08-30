#include "Controllers/Display/DisplayTypes.h"
#include "DisplayMode.h"
#include "IconDisplayMode.h"

/**
 * Default constructor for IconDisplayMode.
 * Initializes the display mode with default values.
 */
IconDisplayMode::IconDisplayMode(const FrameSet* iconFrameSet) 
    : startTime(0), currentIconIndex(-1), iconFrameSet(iconFrameSet) {}

/**
 * Displays the specified icon for a given duration.
 *
 * @param currentTime The current time in milliseconds.
 * @param iconIndex The index of the icon to be displayed.
 * @param duration The duration for which the icon should be displayed (in milliseconds).
 */
IconDisplayMode* IconDisplayMode::displayIcon(unsigned long currentTime, unsigned int iconIndex, unsigned long duration) {
    this->duration = duration;          // Set the duration for the display
    this->startTime = currentTime;      // Record the start time
    this->currentIconIndex = iconIndex; // Set the current icon index
    return this; // Return the current instance for chaining
}

/**
 * Provides the next frame to be displayed.
 * Since this mode displays a static icon, it will always return the same frame.
 *
 * @param currentTime The current time in milliseconds.
 * @return A pointer to the frame to be displayed, or nullptr if the duration has elapsed.
 */
const Frame* IconDisplayMode::nextFrame(unsigned long currentTime) {
    if (currentTime - this->startTime < this->duration) {
        return &(iconFrameSet->frames[currentIconIndex]); // Return a pointer to the current frame
    } else {
        return nullptr; // Return nullptr if the duration has elapsed or iconFrameSet is null
    }
}

/**
 * Indicates whether the display mode is done.
 * This depends on whether the specified duration has elapsed.
 *
 * @param currentTime The current time in milliseconds.
 * @return True if the mode is done, false otherwise.
 */
bool IconDisplayMode::isDone(unsigned long currentTime) {
    return (currentTime - this->startTime >= this->duration); // Check if the duration has elapsed
}
