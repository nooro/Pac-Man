#ifndef WALLS_MANAGER_H_INCLUDED
#define WALLS_MANAGER_H_INCLUDED

#include "../../../System/system.h"
#include "../../../GO/go.h"
#include "vector"

class WallsManager
{
    public:
        static void SetColor(SDL_Color color);
        static void Add(SDL_Rect rect);
        static void Render();
        static void Clear();

        static void Free();

        static SDL_Rect Get(int index);
        static int NumberOfWalls();

    private:
        static SDL_Texture *texture;
        static vector<SDL_Rect> walls;
        static SDL_Color color;
};

#endif // WALLS_MANAGER_H_INCLUDED
