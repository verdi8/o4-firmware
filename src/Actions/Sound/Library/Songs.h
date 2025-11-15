#pragma once

#include "Controllers/Sound/SoundTypes.h"
#include "Notes.h"

const Melody HAPPY_BIRTHDAY_MELODY PROGMEM = {
    25,
    {
        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_D6, 300, 50 },
        { Notes::NOTE_C6, 300, 50 },
        { Notes::NOTE_F6, 300, 50 },
        { Notes::NOTE_E6, 600, 0 },

        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_D6, 300, 50 },
        { Notes::NOTE_C6, 300, 50 },
        { Notes::NOTE_G6, 300, 50 },
        { Notes::NOTE_F6, 600, 0 },

        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_C7, 300, 50 },
        { Notes::NOTE_A6, 300, 50 },
        { Notes::NOTE_F6, 300, 50 },
        { Notes::NOTE_E6, 300, 50 },
        { Notes::NOTE_D6, 600, 0 },

        { Notes::NOTE_As6, 150, 50 },
        { Notes::NOTE_As6, 150, 50 },
        { Notes::NOTE_A6, 300, 50 },
        { Notes::NOTE_F6, 300, 50 },
        { Notes::NOTE_G6, 300, 50 },
        { Notes::NOTE_F6, 600, 0 }
    }
};
