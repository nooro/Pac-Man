#ifndef GAME_PANEL_H_INCLUDED
#define GAME_PANEL_H_INCLUDED

#include <SDL.h>

#include "../../System/system.h"

class GamePanel
{
    public:
        static void Init();

        static int GetWidth();
        static int GetHeight();
        static int GetX();
        static int GetY();

    private:
        static SDL_Rect rect;
};

#endif // GAME_PANEL_H_INCLUDED
