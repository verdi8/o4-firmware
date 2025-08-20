#include "LedMatrixController/LedMatrixControllerTypes.h"
#include "AnimationDisplayMode.h"
#include "Logger.h"

/**
 * Constructor for AnimationDisplayMode.
 * Initializes the animation display mode with default values.
 */
AnimationDisplayMode::AnimationDisplayMode() 
    : currentFrameSetPrgm(nullptr), startTime(0) {}

/**
 * Starts playing the animation with the given FrameSet.
 *
 * @param currentTime The current time in milliseconds.
 * @param frameSet Pointer to the FrameSet containing the animation frames.
 */
AnimationDisplayMode* AnimationDisplayMode::playAnimation(unsigned long currentTime, FrameSet* PROGMEM frameSetPrgm, unsigned long frameDuration, unsigned int repeat) {
    this->currentFrameSetPrgm = frameSetPrgm;  // Set the current frame set
    this->startTime = currentTime;    // Record the start time of the animation
    this->frameDuration = frameDuration; // Set the duration for each frame
    this->repeat = repeat; // Set the number of times the animation should repeat
    return this; // Return the current instance for chaining
}

/**
 * Provides the next frame to be displayed in the animation.
 *
 * @param currentTime The current time in milliseconds.
 * @return A pointer to the frame to be displayed, or nullptr if the animation time has elapsed.
 */
const Frame* AnimationDisplayMode::nextFrame(unsigned long currentTime) {
    if (currentFrameSetPrgm == nullptr) {
        return nullptr; // Return nullptr if the animation time has elapsed or no frames are available
    }
    // Determine the frame index based on elapsed time and frame duration
    unsigned int currentFrameIndex = computeCurrentFrameIndex(currentTime);
    unsigned int frameCountValue = frameCount(currentFrameSetPrgm); // Get the total number of frames in the current frame set
    if (repeat > 0 && currentFrameIndex >= frameCountValue * repeat) {
        return nullptr; // Return nullptr if the frame index exceeds the number of frames
    }
    return &(currentFrameSetPrgm->frames[currentFrameIndex % frameCountValue]); // Return the current frame, wrapping around if necessary
}

/**
 * Indicates whether the animation is done.
 *
 * @param currentTime The current time in milliseconds.
 * @return True if the animation has completed all frames, false otherwise.
 */
bool AnimationDisplayMode::isDone(unsigned long currentTime) {
    if (currentFrameSetPrgm == nullptr) {
        return true; // If no frame set is available, the animation is considered done
    }
    if(repeat == 0) {
        return false; // If repeat is 0, the animation is forever running
    }
    unsigned int frameIndex = computeCurrentFrameIndex(currentTime);
    unsigned int frameCountValue = frameCount(currentFrameSetPrgm);
    if( frameIndex >= frameCountValue * repeat) {
        return true; // If the current frame index exceeds the total frames times repeat, the animation is done
    }
    return false; // Otherwise, the animation is still running
}

inline unsigned int AnimationDisplayMode::computeCurrentFrameIndex(unsigned long currentTime) {
    unsigned int frameIndex = (currentTime - startTime) / frameDuration;
    // Determine the frame index based on elapsed time and frame duration
    return frameIndex;
}

inline unsigned int AnimationDisplayMode::frameCount(FrameSet* PROGMEM frameSetPrgm) {
    return pgm_read_word(&(frameSetPrgm->count)); // Read the number of frames from the FrameSet in program memory
}
