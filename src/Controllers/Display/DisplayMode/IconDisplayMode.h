#ifndef ICON_DISPLAY_MODE_H
#define ICON_DISPLAY_MODE_H

#include "Controllers/Display/DisplayTypes.h"
#include "DisplayMode.h"


/**
 * IconDisplayMode class for displaying a single static icon on the LED matrix.
 * This mode allows displaying an icon for a specified duration.
 */
class IconDisplayMode : public DisplayMode {
private:
    unsigned long duration;       // The duration for which the icon should be displayed
    unsigned long startTime;      // The time when the display started
    unsigned int currentIconIndex;         // The index of the current icon being displayed
    const FrameSet* PROGMEM iconFrameSetPrgm; // A set of frames representing the icon (final and immutable)

public:
    /**
     * Default constructor for IconDisplayMode.
     * Initializes the display mode with default values.
     */
    IconDisplayMode(const FrameSet* iconFrameSet);

    /**
     * Displays the specified icon for a given duration.
     *
     * @param currentTime The current time in milliseconds.
     * @param iconIndex The index of the icon to be displayed.
     * @param duration The duration for which the icon should be displayed (in milliseconds).
     */
    IconDisplayMode* displayIcon(unsigned long currentTime, unsigned int iconIndex, unsigned long duration);

    /**
     * Provides the next frame to be displayed.
     * Since this mode displays a static icon, it will always return the same frame.
     *
     * @param currentTime The current time in milliseconds.
     * @return A pointer to the frame to be displayed.
     */
    const Frame* nextFrame(unsigned long currentTime) override;

    /**
     * Indicates whether the display mode is done.
     * This depends on whether the specified duration has elapsed.
     *
     * @param currentTime The current time in milliseconds.
     * @return True if the mode is done, false otherwise.
     */
    bool isDone(unsigned long currentTime) override;
};

#endif // ICON_DISPLAY_MODE_H
