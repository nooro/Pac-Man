#ifndef GENEREAL_H_INCLUDED
#define GENEREAL_H_INCLUDED

#include <SDL.h>
#include <iostream>
#include <time.h>

class General
{
    public:
        static int RandomNumber(int min, int max);

        static SDL_Color Colors[7];

    private:
        static bool random_is_seed;
};

#endif // GENEREAL_H_INCLUDED
