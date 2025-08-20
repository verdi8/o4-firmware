#ifndef LED_MATRIX_CONTROLLER_H
#define LED_MATRIX_CONTROLLER_H

#include <Arduino.h>
#include <LedControl.h>
#include "LedMatrixControllerTypes.h" 
#include "DisplayMode/DisplayMode.h"
#include "DisplayMode/IconDisplayMode.h"
#include "DisplayMode/AnimationDisplayMode.h"


/**
 * @class LedMatrixController
 * @brief Manages the LED Matrix display, including icons, animations, and display modes.
 * 
 * This class provides functionality to control an LED Matrix using the LedControl library.
 * It supports displaying static icons, random icons, animations, and managing different display modes.
 * 
 * @note The LED matrix index is defined as a `constexpr` variable (`LED_MATRIX_INDEX`).
 */
class LedMatrixController
{
  private:
    // Private member properties
    LedControl* ledControl; // The LedControl object from the LedControl library
    bool doFlipX; // Whether to flip the X axis    DisplayMode* iconDisplayModeInstance; // Instance for managing icon display mode
    IconDisplayMode* iconDisplayModeInstance; // Instance for managing icon display mode
    AnimationDisplayMode* animationDisplayModeInstance; // Instance for managing animation display mode
    DisplayMode* currentDisplayMode; // The current display mode of the LED Matrix

    // Private methods
    void displayFrame(const Frame* frame); // Display a frame on the LED Matrix
    bool isEndOfFrameSet(FrameSet* frameset, unsigned int frameIndex); // Check if the end of the frame set has been reached
    byte flipX(byte b); // Flip the byte to display the correct orientation

  public:
    /**
     * Constructor
     * @param dataPin The data pin of the LED Matrix
     * @param clkPin The clock pin of the LED Matrix
     * @param csPin The chip select pin of the LED Matrix
     * @param doFlipX Whether to flip the X axis
     * @param iconFrameset The frameset to use for displaying icons
     */
    LedMatrixController(int dataPin, int clkPin, int csPin, bool doFlipX, const FrameSet* iconFrameset);

    /**
     * Display an icon on the LED Matrix
     * @param index The index in the ICON_FRAMESET
     */
    void displayIcon(unsigned long currentTime, unsigned int iconIndex, unsigned long duration);

    /**
     * Play an animation on the LED Matrix.
     *
     * @param currentTime The current time in milliseconds when the animation starts.
     * @param frameset Pointer to the FrameSet containing the animation frames.
     * @param frameDuration Duration for each frame in milliseconds.
     * @param repeat Number of times the animation should repeat. Use 0 for infinite looping.
     */
    void playAnimation(unsigned long currentTime, FrameSet* frameset, unsigned long frameDuration, unsigned int repeat);

    /**
     * Clear the LED Matrix display and reset the current display mode.
     */
    void clearDisplay();

    /**
     * Update the display
     */
    void update(unsigned long currentTime);
};

#endif