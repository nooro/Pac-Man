#ifndef PORTAL_H_INCLUDED
#define PORTAL_H_INCLUDED

#include "../../../System/system.h"
#include "../../../GO/go.h"

class Portal
{
    public:
        static void SetColor(SDL_Color color);

        static bool Add(SDL_Rect first_rect, SDL_Rect second_rect);
        static void Render();
        static void Clear();

        static void Free();

    private:
        static SDL_Texture *texture;
        static SDL_Color color;
        static SDL_Rect entrances[];
        static int number_of_entrances;
};

#endif // PORTAL_H_INCLUDED
