#ifndef SOUND_TYPES_H
#define SOUND_TYPES_H

// Notes found at: https://docs.arduino.cc/built-in-examples/digital/toneMelody/

/**
 * Note structure to represent a musical note in a melody.
 */
struct MelodyNote {
    float frequency; // Frequency in Hertz
    unsigned long duration; // Duration in milliseconds
    unsigned long pause; // Pause after the note in milliseconds
};

/**
 * Melody structure to represent a sequence of musical notes.
 */
struct Melody {
    unsigned int melodyNoteCount;
    MelodyNote melodyNotes[];
};

#endif // SOUND_TYPES_H
