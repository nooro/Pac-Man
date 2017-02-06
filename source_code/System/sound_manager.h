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
            GetCoin
        };

        static bool Init();
        static void Close();

        static void Play(SoundManager::Sounds sound);

    private:
        static Mix_Chunk *get_coin;
};

#endif // SOUND_MANAGER_H_INCLUDED
