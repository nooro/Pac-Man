#ifndef GENEREAL_H_INCLUDED
#define GENEREAL_H_INCLUDED

#include <SDL.h>
#include "SDL_ttf.h"
#include <iostream>
#include <time.h>

#define BLUE General::Colors[0]
#define GREEN General::Colors[1]
#define ORANGE General::Colors[2]
#define PURPLE General::Colors[3]
#define RED General::Colors[4]
#define WHITE General::Colors[5]
#define PINK General::Colors[6]

class General
{
    public:
        static int RandomNumber(int min, int max);

        static SDL_Color Colors[7];

        enum Direction { Right, Left, Up = 90, Down = 270 };

    private:
        static bool random_is_seed;
};

#endif // GENEREAL_H_INCLUDED
