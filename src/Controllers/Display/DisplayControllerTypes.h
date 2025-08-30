#ifndef DISPLAY_CONTROLLER_TYPES_H
#define DISPLAY_CONTROLLER_TYPES_H

#include <Arduino.h>

/** Frame typedef for an 8x8 LED matrix frame */
typedef byte Frame[8];

/** FrameSet structure */
struct FrameSet
{
    /** Number of frames in the frameset */
    unsigned int count;

    /** Array of 8x8 frames */
    Frame frames[];
};

#endif
