#ifndef SOUND_TYPES_H
#define SOUND_TYPES_H

// Notes found at: https://docs.arduino.cc/built-in-examples/digital/toneMelody/

namespace Notes {
    // Prefixed by NOTE_ to avoid conflicts with Arduino pin names for certain notes
    constexpr unsigned int NOTE_B0  = 31;
    constexpr unsigned int NOTE_C1  = 33;
    constexpr unsigned int NOTE_Cs1 = 35;
    constexpr unsigned int NOTE_Db1 = NOTE_Cs1;
    constexpr unsigned int NOTE_D1  = 37;
    constexpr unsigned int NOTE_Ds1 = 39;
    constexpr unsigned int NOTE_Eb1 = NOTE_Ds1;
    constexpr unsigned int NOTE_E1  = 41;
    constexpr unsigned int NOTE_F1  = 44;
    constexpr unsigned int NOTE_Fs1 = 46;
    constexpr unsigned int NOTE_Gb1 = NOTE_Fs1;
    constexpr unsigned int NOTE_G1  = 49;
    constexpr unsigned int NOTE_Gs1 = 52;
    constexpr unsigned int NOTE_Ab1 = NOTE_Gs1;
    constexpr unsigned int NOTE_A1  = 55;
    constexpr unsigned int NOTE_As1 = 58;
    constexpr unsigned int NOTE_Bb1 = NOTE_As1;
    constexpr unsigned int NOTE_B1  = 62;
    constexpr unsigned int NOTE_C2  = 65;
    constexpr unsigned int NOTE_Cs2 = 69;
    constexpr unsigned int NOTE_Db2 = NOTE_Cs2;
    constexpr unsigned int NOTE_D2  = 73;
    constexpr unsigned int NOTE_Ds2 = 78;
    constexpr unsigned int NOTE_Eb2 = NOTE_Ds2;
    constexpr unsigned int NOTE_E2  = 82;
    constexpr unsigned int NOTE_F2  = 87;
    constexpr unsigned int NOTE_Fs2 = 93;
    constexpr unsigned int NOTE_Gb2 = NOTE_Fs2;
    constexpr unsigned int NOTE_G2  = 98;
    constexpr unsigned int NOTE_Gs2 = 104;
    constexpr unsigned int NOTE_Ab2 = NOTE_Gs2;
    constexpr unsigned int NOTE_A2  = 110;
    constexpr unsigned int NOTE_As2 = 117;
    constexpr unsigned int NOTE_Bb2 = NOTE_As2;
    constexpr unsigned int NOTE_B2  = 123;
    constexpr unsigned int NOTE_C3  = 131;
    constexpr unsigned int NOTE_Cs3 = 139;
    constexpr unsigned int NOTE_Db3 = NOTE_Cs3;
    constexpr unsigned int NOTE_D3  = 147;
    constexpr unsigned int NOTE_Ds3 = 156;
    constexpr unsigned int NOTE_Eb3 = NOTE_Ds3;
    constexpr unsigned int NOTE_E3  = 165;
    constexpr unsigned int NOTE_F3  = 175;
    constexpr unsigned int NOTE_Fs3 = 185;
    constexpr unsigned int NOTE_Gb3 = NOTE_Fs3;
    constexpr unsigned int NOTE_G3  = 196;
    constexpr unsigned int NOTE_Gs3 = 208;
    constexpr unsigned int NOTE_Ab3 = NOTE_Gs3;
    constexpr unsigned int NOTE_A3  = 220;
    constexpr unsigned int NOTE_As3 = 233;
    constexpr unsigned int NOTE_Bb3 = NOTE_As3;
    constexpr unsigned int NOTE_B3  = 247;
    constexpr unsigned int NOTE_C4  = 262;
    constexpr unsigned int NOTE_Cs4 = 277;
    constexpr unsigned int NOTE_Db4 = NOTE_Cs4;
    constexpr unsigned int NOTE_D4  = 294;
    constexpr unsigned int NOTE_Ds4 = 311;
    constexpr unsigned int NOTE_Eb4 = NOTE_Ds4;
    constexpr unsigned int NOTE_E4  = 330;
    constexpr unsigned int NOTE_F4  = 349;
    constexpr unsigned int NOTE_Fs4 = 370;
    constexpr unsigned int NOTE_Gb4 = NOTE_Fs4;
    constexpr unsigned int NOTE_G4  = 392;
    constexpr unsigned int NOTE_Gs4 = 415;
    constexpr unsigned int NOTE_Ab4 = NOTE_Gs4;
    constexpr unsigned int NOTE_A4  = 440;
    constexpr unsigned int NOTE_As4 = 466;
    constexpr unsigned int NOTE_Bb4 = NOTE_As4;
    constexpr unsigned int NOTE_B4  = 494;
    constexpr unsigned int NOTE_C5  = 523;
    constexpr unsigned int NOTE_Cs5 = 554;
    constexpr unsigned int NOTE_Db5 = NOTE_Cs5;
    constexpr unsigned int NOTE_D5  = 587;
    constexpr unsigned int NOTE_Ds5 = 622;
    constexpr unsigned int NOTE_Eb5 = NOTE_Ds5;
    constexpr unsigned int NOTE_E5  = 659;
    constexpr unsigned int NOTE_F5  = 698;
    constexpr unsigned int NOTE_Fs5 = 740;
    constexpr unsigned int NOTE_Gb5 = NOTE_Fs5;
    constexpr unsigned int NOTE_G5  = 784;
    constexpr unsigned int NOTE_Gs5 = 831;
    constexpr unsigned int NOTE_Ab5 = NOTE_Gs5;
    constexpr unsigned int NOTE_A5  = 880;
    constexpr unsigned int NOTE_As5 = 932;
    constexpr unsigned int NOTE_Bb5 = NOTE_As5;
    constexpr unsigned int NOTE_B5  = 988;
    constexpr unsigned int NOTE_C6  = 1047;
    constexpr unsigned int NOTE_Cs6 = 1109;
    constexpr unsigned int NOTE_Db6 = NOTE_Cs6;
    constexpr unsigned int NOTE_D6  = 1175;
    constexpr unsigned int NOTE_Ds6 = 1245;
    constexpr unsigned int NOTE_Eb6 = NOTE_Ds6;
    constexpr unsigned int NOTE_E6  = 1319;
    constexpr unsigned int NOTE_F6  = 1397;
    constexpr unsigned int NOTE_Fs6 = 1480;
    constexpr unsigned int NOTE_Gb6 = NOTE_Fs6;
    constexpr unsigned int NOTE_G6  = 1568;
    constexpr unsigned int NOTE_Gs6 = 1661;
    constexpr unsigned int NOTE_Ab6 = NOTE_Gs6;
    constexpr unsigned int NOTE_A6  = 1760;
    constexpr unsigned int NOTE_As6 = 1865;
    constexpr unsigned int NOTE_Bb6 = NOTE_As6;
    constexpr unsigned int NOTE_B6  = 1976;
    constexpr unsigned int NOTE_C7  = 2093;
    constexpr unsigned int NOTE_Cs7 = 2217;
    constexpr unsigned int NOTE_Db7 = NOTE_Cs7;
    constexpr unsigned int NOTE_D7  = 2349;
    constexpr unsigned int NOTE_Ds7 = 2489;
    constexpr unsigned int NOTE_Eb7 = NOTE_Ds7;
    constexpr unsigned int NOTE_E7  = 2637;
    constexpr unsigned int NOTE_F7  = 2794;
    constexpr unsigned int NOTE_Fs7 = 2960;
    constexpr unsigned int NOTE_Gb7 = NOTE_Fs7;
    constexpr unsigned int NOTE_G7  = 3136;
    constexpr unsigned int NOTE_Gs7 = 3322;
    constexpr unsigned int NOTE_Ab7 = NOTE_Gs7;
    constexpr unsigned int NOTE_A7  = 3520;
    constexpr unsigned int NOTE_As7 = 3729;
    constexpr unsigned int NOTE_Bb7 = NOTE_As7;
    constexpr unsigned int NOTE_B7  = 3951;
    constexpr unsigned int NOTE_C8  = 4186;
    constexpr unsigned int NOTE_Cs8 = 4435;
    constexpr unsigned int NOTE_Db8 = NOTE_Cs8;
    constexpr unsigned int NOTE_D8  = 4699;
    constexpr unsigned int NOTE_Ds8 = 4978;
}

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
