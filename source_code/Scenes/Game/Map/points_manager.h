#ifndef POINTS_MANAGER_H_INCLUDED
#define POINTS_MANAGER_H_INCLUDED

#include "../../../System/system.h"
#include "../../../GO/go.h"
#include "vector"

class PointsManager
{
    public:
        static void SetColor(SDL_Color color);

        static void Add(SDL_Rect rect);
        static void Delete(int index);

        static void Render();
        static void Clear();

        static void Free();

        static SDL_Rect Get(int index);
        static int NumberOfPoints();

    private:
        static SDL_Texture *texture;
        static vector<SDL_Rect> points;
        static SDL_Color color;
};

#endif // POINTS_MANAGER_H_INCLUDED
