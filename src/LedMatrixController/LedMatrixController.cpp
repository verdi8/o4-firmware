#include "LedMatrixController.h"
#include <LedControl.h>
#include "LedMatrixControllerTypes.h"
#include "DisplayMode/DisplayMode.h"
#include "DisplayMode/IconDisplayMode.h"
#include "DisplayMode/AnimationDisplayMode.h"
#include "logger.h"

constexpr int LED_MATRIX_INDEX = 0; // Define LED_MATRIX_INDEX as constexpr for better optimization and clarity

LedMatrixController::LedMatrixController(int dataPin, int clkPin, int csPin, bool doFlipX, const FrameSet* iconFrameset)
    : ledControl(new LedControl(dataPin, clkPin, csPin, 1)),
      doFlipX(doFlipX),
      iconDisplayModeInstance(new IconDisplayMode(iconFrameset)),
      animationDisplayModeInstance(new AnimationDisplayMode()), 
      currentDisplayMode(nullptr) // Initialize currentDisplayMode to nullptr
{
    ledControl->shutdown(LED_MATRIX_INDEX, false);
    ledControl->setIntensity(LED_MATRIX_INDEX, 8);
    ledControl->clearDisplay(LED_MATRIX_INDEX);
};

void LedMatrixController::displayIcon(unsigned long currentTime, unsigned int iconIndex, unsigned long duration)
{
    this->currentDisplayMode = this->iconDisplayModeInstance->displayIcon(currentTime, iconIndex, duration); // Display the icon for 2000 ms
};

void LedMatrixController::playAnimation(unsigned long currentTime, FrameSet* PROGMEM frameSetPrgm, unsigned long frameDuration, unsigned int repeat)
{
    this->currentDisplayMode = this->animationDisplayModeInstance->playAnimation(currentTime, frameSetPrgm, frameDuration, repeat); // Start the animation
};

void LedMatrixController::clearDisplay()
{
    ledControl->clearDisplay(LED_MATRIX_INDEX); // Clear the LED Matrix display
};

void LedMatrixController::update(unsigned long currentTime)
{
    if(this->currentDisplayMode == nullptr)
    {
        return; // If no display mode is set, do nothing
    }


    const Frame* frame = this->currentDisplayMode->nextFrame(currentTime); // Get the next frame from the current display mode
    if (frame != nullptr)
    {
        // If a frame is available, display it
        this->displayFrame(frame);
    }
    
    if (this->currentDisplayMode->isDone(currentTime))
    {
        // If the current display mode is done, clear the display and reset the current display mode
        this->clearDisplay();
        this->currentDisplayMode = nullptr; // Reset the current display mode to nullptr
    }
};

void LedMatrixController::displayFrame(const Frame* frame)
{
    for (int i = 0; i < 8; i++)
    {
        // Read the column data correctly
        byte col = pgm_read_byte(((const byte*) frame) + i);
        if (this->doFlipX)
        {
            col = flipX(col);
        }
        ledControl->setColumn(LED_MATRIX_INDEX, i, col); // Ensure correct index is used
    }
};

byte LedMatrixController::flipX(byte b)
{
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
};
