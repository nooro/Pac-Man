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
        static void GetPlayerInput();
        static void Render();

        static bool is_active;

        static SDL_Rect game_panel;
};

#endif // GAME_H_INCLUDED
