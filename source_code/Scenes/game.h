#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../System/system.h"
#include "../Entities/pac_man.h"

class GameScene
{
    public:
        static bool Init();
        static void Play();

    private:
        static bool is_active;
};

#endif // GAME_H_INCLUDED
