#pragma once

#include "Hardware/HAL/HAL.h"

/** Frame typedef for an 8x8 LED matrix frame */
typedef byte Frame[8];

/** FrameSet structure */
struct FrameSet
{
    /** Number of frames in the frameset */
    unsigned int frameCount;

    /** Array of 8x8 frames */
    Frame frames[];
};
