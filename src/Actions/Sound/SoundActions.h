#pragma once

#include "Actions/Actions.h"
#include "Controllers/Sound/SoundController.h"

/**
 * High-level interface for sound actions.
 */
class SoundActions : public Actions {
private:
    SoundController* soundController; // Pointer to the SoundController instance that performs the actual sound actions

public:
    /**
     * @brief Constructor that initializes the SoundActions with a SoundController instance.
     * 
     * @param soundController Pointer to the SoundController instance.
     */
    SoundActions(SoundController* soundController);

    /**
     * @brief Plays the connect sound.
     * 
     * @param currentTime The current time in milliseconds.
     */
    void playConnectJingle(unsigned long currentTime);

    /**
     * @brief Plays the happy birthday song.
     * 
     * @param currentTime The current time in milliseconds.
     */
    void singHappyBirthday(unsigned long currentTime);

};
