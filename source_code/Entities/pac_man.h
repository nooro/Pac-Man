#ifndef PAC_MAN_H_INCLUDED
#define PAC_MAN_H_INCLUDED

#include "../System/system.h"
#include "../GO/go.h"

class PacMan
{
    public:
        static bool Init();
        static void Render();

    private:
        static SDL_Rect rect;
        static bool is_alive, is_walking;
        static int lives;
        static Image idle_image;
        static Animation walk_animation;
        static Animation die_animation;
};

#endif // PAC_MAN_H_INCLUDED
