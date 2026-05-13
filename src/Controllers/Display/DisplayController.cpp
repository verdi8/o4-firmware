#include "DisplayController.h"
#include "Hardware/HAL/HALLedControl.h"
#include "Hardware/HAL/HAL.h"
#include "Config.h"
#include "DisplayTypes.h"
#include "DisplayMode/DisplayMode.h"
#include "DisplayMode/StillImageDisplayMode.h"
#include "DisplayMode/AnimationDisplayMode.h"
#include "logger.h"

constexpr int LED_MATRIX_INDEX = 0; // Define LED_MATRIX_INDEX as constexpr for better optimization and clarity

DisplayController::DisplayController(HAL* hal, TimeProvider* timeProvider, PinNumber dataPin, PinNumber clkPin, PinNumber csPin, bool doFlipX)
    : ledControl(hal->newLedControl(dataPin, clkPin, csPin)),
      programSpaceHelper(hal->newProgramSpaceHelper()),
      timeProvider(timeProvider),
      doFlipX(doFlipX),
      stillImageDisplayModeInstance(new StillImageDisplayMode(programSpaceHelper)),
      animationDisplayModeInstance(new AnimationDisplayMode(programSpaceHelper)),
      currentDisplayMode(nullptr) // Initialize currentDisplayMode to nullptr
{
    ledControl->shutdown(LED_MATRIX_INDEX, false);
    ledControl->setIntensity(LED_MATRIX_INDEX, 8);
    ledControl->clearDisplay(LED_MATRIX_INDEX);
};

void DisplayController::displayImage(const FrameSet *PROGMEM iconFrameSetPrgm, unsigned int iconIndex, unsigned long duration)
{
    unsigned long currentTime = timeProvider->getCurrentTime(); // Get the current time from the TimeProvider
    this->currentDisplayMode = this->stillImageDisplayModeInstance->displayIcon(currentTime, iconFrameSetPrgm, iconIndex, duration); // Display the icon for 2000 ms
};

void DisplayController::playAnimation(FrameSet *PROGMEM frameSetPrgm, unsigned long frameDuration, unsigned int repeat)
{
    unsigned long currentTime = timeProvider->getCurrentTime(); // Get the current time from the TimeProvider
    this->currentDisplayMode = this->animationDisplayModeInstance->playAnimation(currentTime, frameSetPrgm, frameDuration, repeat); // Start the animation
};

void DisplayController::clearDisplay()
{
    ledControl->clearDisplay(LED_MATRIX_INDEX); // Clear the LED Matrix display
};

void DisplayController::update()
{
    if (this->currentDisplayMode == nullptr)
    {
        return; // If no display mode is set, do nothing
    }
    unsigned long currentTime = timeProvider->getCurrentTime(); // Get the current time from the TimeProvider

    const Frame *frame = this->currentDisplayMode->nextFrame(currentTime); // Get the next frame from the current display mode
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

bool DisplayController::isDone()
{
    // If no display mode is set, the controller is considered done
    if (this->currentDisplayMode == nullptr)
    {
        return true;
    }
    unsigned long currentTime = timeProvider->getCurrentTime(); // Get the current time from the TimeProvider
    // Check if the current display mode reports that the operation is done
    return this->currentDisplayMode->isDone(currentTime);
}

void DisplayController::displayFrame(const Frame *frame)
{
    for (int i = 0; i < 8; i++)
    {
        // Read the column data correctly
        byte col = programSpaceHelper->readByte(((const byte *)frame) + i);
        if (this->doFlipX)
        {
            col = flipX(col);
        }
        ledControl->setColumn(LED_MATRIX_INDEX, i, col); // Ensure correct index is used
    }
};

byte DisplayController::flipX(byte b)
{
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
};
