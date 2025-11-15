#include "SoundController.h"
#include "logger.h"
#include "Hardware/HAL/HAL.h"

/**
 * @brief Constructs a SoundController with the specified buzzer pin and time provider.
 */
SoundController::SoundController(HAL* hal, TimeProvider *timeProvider, PinNumber buzzerPin) : timeProvider(timeProvider), buzzerPin(buzzerPin), currentMelodyPrgm(nullptr), currentFrequency(NO_SOUND_FREQUENCY)
{
    this->tone = hal->newTone(buzzerPin);
    this->programSpaceHelper = hal->newProgramSpaceHelper();
    mute();
}

void SoundController::playMelody(unsigned long currentTime, const Melody *PROGMEM melodyPrgm)
{
    currentMelodyPrgm = melodyPrgm;
    currentNoteIndex = 0;
    currentNoteStartTime = currentTime;
    currentFrequency = NO_SOUND_FREQUENCY;
}

void SoundController::mute()
{
    currentMelodyPrgm = nullptr;
    stopPlayingMelodyNote();
}

void SoundController::update()
{

    if (currentMelodyPrgm == nullptr)
    {
        return; // No melody is being played
    }
    unsigned long currentTime = timeProvider->getCurrentTime();
    MelodyNote melodyNote = readPrgmMelodyNote(currentMelodyPrgm, currentNoteIndex);
    unsigned long elapsedTime = currentTime - currentNoteStartTime;
    if (elapsedTime < melodyNote.duration)
    {
        // Still playing the current note
        playMelodyNote(melodyNote);
    }
    else if (elapsedTime < melodyNote.duration + melodyNote.pause)
    {
        // In the pause after the note
        if (currentFrequency != NO_SOUND_FREQUENCY)
        {
            stopPlayingMelodyNote();
        }
    }
    else
    {
        if (currentNoteIndex == melodyNoteCount(currentMelodyPrgm) - 1)
        {
            // It was the last note, end the melody
            mute();
        }
        else
        {
            // Start the next note (at the next update)
            currentNoteStartTime = currentTime;
            currentNoteIndex++;
        }
    }
}

bool SoundController::isDone()
{
    return currentMelodyPrgm == nullptr;
}

void SoundController::stopPlayingMelodyNote()
{
    tone->noTone();
    currentFrequency = NO_SOUND_FREQUENCY;
}

void SoundController::playMelodyNote(MelodyNote melodyNote)
{
    if (melodyNote.frequency == currentFrequency)
    {
        return; // The note is already playing, do nothing
    }

    if (melodyNote.frequency == NO_SOUND_FREQUENCY)
    {
        tone->noTone();
    }
    else
    {
        tone->tone(melodyNote.frequency, melodyNote.duration);
    }
    currentFrequency = melodyNote.frequency;
}

inline MelodyNote SoundController::readPrgmMelodyNote(const Melody *PROGMEM melodyPrgm, unsigned int index)
{
    MelodyNote note;
    memcpy_P(&note, &(melodyPrgm->melodyNotes[index]), sizeof(MelodyNote));
    return note;
}

inline unsigned int SoundController::melodyNoteCount(const Melody *PROGMEM melodyPrgm)
{
    return programSpaceHelper->readWord(&(melodyPrgm->melodyNoteCount)); // Read the number of notes from the Melody in program memory
}
