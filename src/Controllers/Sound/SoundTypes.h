#ifndef SOUND_TYPES_H
#define SOUND_TYPES_H


/**
 * Note structure to represent a musical note in a melody.
 */
struct Note {
    float frequency; // Frequency in Hertz
    unsigned long duration; // Duration in milliseconds
    unsigned long pause; // Pause after the note in milliseconds
};

/**
 * Melody structure to represent a sequence of musical notes.
 */
struct Melody {
    unsigned int noteCount;
    Note notes[];
};

#endif // SOUND_TYPES_H
