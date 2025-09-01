#include "SoundActions.h"
#include "Controllers/Sound/SoundController.h"
#include "Library/Jingles.h"
#include "Library/Songs.h"


SoundActions::SoundActions(SoundController *soundController)
    : soundController(soundController)
{
}

void SoundActions::playConnectJingle(unsigned long currentTime)
{
    soundController->playMelody(currentTime, &CONNECT_MELODY);
}

void SoundActions::singHappyBirthday(unsigned long currentTime)
{
    soundController->playMelody(currentTime, &HAPPY_BIRTHDAY_MELODY);
}
