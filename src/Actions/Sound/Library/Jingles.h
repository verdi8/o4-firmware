#pragma once
#include "Controllers/Sound/SoundTypes.h"
#include "Notes.h"


const Melody CONNECT_MELODY PROGMEM = {
    4,
    {
        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_E6, 150, 50 },
        { Notes::NOTE_G6, 150, 50 },
        { Notes::NOTE_C7, 300, 0 }
    }
};
