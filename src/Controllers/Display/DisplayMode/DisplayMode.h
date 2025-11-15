#pragma once
#include "Controllers/Display/DisplayTypes.h"

/**
 * DisplayMode interface for managing different display modes in the LED Matrix Controller.
 */
class DisplayMode {
public:

    /**
     * Gives the next frame to be displayed.
     */
    virtual const Frame* nextFrame(unsigned long currentTime) = 0;

    /**
     * Tells if the display mode is done (i.e., if it has finished displaying all frames).
     */
    virtual bool isDone(unsigned long currentTime) = 0;

};
