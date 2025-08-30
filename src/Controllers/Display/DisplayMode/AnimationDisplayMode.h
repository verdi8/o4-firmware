#ifndef ANIMATION_DISPLAY_MODE_H
#define ANIMATION_DISPLAY_MODE_H

#include "Controllers/Display/DisplayTypes.h"
#include "DisplayMode.h"

/**
 * AnimationDisplayMode class for displaying a sequence of frames as an animation.
 */
class AnimationDisplayMode : public DisplayMode {
private:
    FrameSet* PROGMEM currentFrameSetPrgm;   // Pointer to the set of frames for the animation
    unsigned long frameDuration; // Duration for each frame in milliseconds
    unsigned long startTime;     // Start time of the animation
    unsigned int repeat; // Number of times the animation should repeat

    inline unsigned int computeCurrentFrameIndex(unsigned long currentTime);
    inline unsigned int frameCount(FrameSet* PROGMEM frameSetPrgm);

public:
    /**
     * Constructor for AnimationDisplayMode.
     * Initializes the animation display mode with a given FrameSet.
     *
     * @param frameSet Pointer to the FrameSet containing the animation frames.
     */
    AnimationDisplayMode();

    /**
     * Starts playing the animation with the given FrameSet.
     *
     * @param currentTime The current time in milliseconds when the animation starts.
     * @param FrameSetPrgm Pointer to the FrameSet stored in program memory containing the animation frames.
     * @param frameDuration Duration for each frame in milliseconds.
     * @param repeat Number of times the animation should repeat.
     * @return A pointer to the AnimationDisplayMode instance for method chaining.
     */
    AnimationDisplayMode* playAnimation(unsigned long currentTime, FrameSet* PROGMEM FrameSetPrgm, unsigned long frameDuration, unsigned int repeat);

    /**
     * Provides the next frame to be displayed in the animation.
     *
     * @param currentTime The current time in milliseconds.
     * @return A pointer to the frame to be displayed.
     */
    const Frame* nextFrame(unsigned long currentTime) override;

    /**
     * Indicates whether the animation is done.
     *
     * @param currentTime The current time in milliseconds.
     * @return True if the animation has completed all frames, false otherwise.
     */
    bool isDone(unsigned long currentTime) override;
};

#endif // ANIMATION_DISPLAY_MODE_H
