#ifndef SOUND_MANAGER_H_INCLUDED
#define SOUND_MANAGER_H_INCLUDED

#include <SDL_mixer.h>
#include "error_manager.h"
#include "resources_paths.h"

#define NO_LOOP 0

class SoundManager
{
    public:
        enum Sounds
        {
            GetCoin,
            Click
        };

        static bool Init();
        static void Free();

        static void Play(SoundManager::Sounds sound);

    private:
        static Mix_Chunk *get_coin;
        static Mix_Chunk *click;
};

#endif // SOUND_MANAGER_H_INCLUDED
