#ifndef BONUS_POINTS_MANAGER_H_INCLUDED
#define BONUS_POINTS_MANAGER_H_INCLUDED

#include "../../../System/system.h"
#include "../../../GO/go.h"
#include "vector"

class BonusPointsManager
{
    public:
        static void SetColor(SDL_Color color);

        static void Add(SDL_Rect rect);
        static void Delete(int index);

        static void Render();
        static void Clear();

        static SDL_Rect Get(int index);
        static int NumberOfPoints();

        static void Free();
    private:
        static SDL_Texture *texture;
        static vector<SDL_Rect> points;
        static SDL_Color color;
};

#endif // BONUS_POINTS_MANAGER_H_INCLUDED
