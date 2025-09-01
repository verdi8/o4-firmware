#pragma once

#include <Arduino.h>
#include "Hardware/Config.h"
#include "Controllers/Controller.h" // Include the Controller interface
#include "SoundTypes.h" // Include the Melody and MelodyNote structs
#include "Controllers/TimeProvider.h"

constexpr unsigned int NO_SOUND_FREQUENCY = 0; // Constant to represent no frequency

/**
 * @class SoundController
 * @brief Manages sound playback using a buzzer or speaker.
 */
class SoundController : public Controller {
private:
    TimeProvider* timeProvider;            // Pointer to the TimeProvider for getting current time
    PinNumber buzzerPin;                      // Pin connected to the buzzer or speaker
    const Melody* PROGMEM currentMelodyPrgm;    // Pointer to the current melody being played, nullptr if no melody is playing
    unsigned int currentNoteIndex;      // Index of the current note being played
    unsigned long currentNoteStartTime; // Start time of the current note
    unsigned int currentFrequency;     // Frequency of the current note being played, 0 if no note is being played

    void playMelodyNote(MelodyNote melodyNote); // Plays a single note for its duration
    void stopPlayingMelodyNote();       // Stops playing the current note
    inline unsigned int melodyNoteCount(const Melody* PROGMEM melodyPrgm);
    inline MelodyNote readPrgmMelodyNote(const Melody* PROGMEM melodyPrgm, unsigned int index); // Reads a MelodyNote from program memory
    inline void endOfMelody();            // Ends the current melody playback
public:
    /**
     * @brief Constructs a SoundController with the specified buzzer pin.
     * 
     * @param buzzerPin The pin connected to the buzzer or speaker.
     */
    SoundController(TimeProvider* timeProvider, PinNumber buzzerPin);

    /**
     * @brief Plays a melody consisting of a sequence of notes.
     * 
     * @param melody A Melody struct containing the sequence of notes.
     */
    void playMelody(unsigned long currentTime, const Melody* PROGMEM melodyPrgm);

    /**
     * @brief Stops any currently playing sound.
     */
    void mute();

    /**
     * @brief Updates the state of the SoundController.
     * 
     * @param currentTime The current time in milliseconds.
     */
    void update() override;

    /**
     * @brief Checks if the current sound playback is complete.
     * 
     * @param currentTime The current time in milliseconds.
     * @return true if the sound playback is complete, false otherwise.
     */
    bool isDone() override;
};

