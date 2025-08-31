

#ifndef SOUNDS_H
#define SOUNDS_H

#include "Controllers/Sound/SoundTypes.h"

#define S_connection   0
#define S_disconnection 1
#define S_buttonPushed  2
#define S_mode1     3
#define S_mode2     4
#define S_mode3     5
#define S_surprise    6
#define S_OhOoh     7
#define S_OhOoh2    8
#define S_cuddly    9
#define S_sleeping    10
#define S_happy     11
#define S_superHappy  12
#define S_happy_short   13
#define S_sad       14
#define S_confused    15
#define S_fart1     16
#define S_fart2     17
#define S_fart3     18


const Melody CONNECT_MELODY PROGMEM = {
    4,
    {
        { Notes::NOTE_C6, 150, 50 },
        { Notes::NOTE_E6, 150, 50 },
        { Notes::NOTE_G6, 150, 50 },
        { Notes::NOTE_C7, 300, 0 }
    }
};

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


#endif
