#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "fstream"

#include "../../../System/system.h"

#include "../game_panel.h"
#include "../Entities/pac_man.h"

#include "walls_manager.h"
#include "points_manager.h"
#include "bonus_points_manager.h"
#include "portal.h"

#define WALL        '#'
#define PORTAL      'O'
#define POINT       '*'
#define BONUS_POINT '$'
#define PACMAN      '@'
#define NEW_LINE    '\n'
#define EMPTY_SPACE ' '

class Map
{
    public:
        bool Load(string file_path);
        void Free();

        void Render();

        void SetWallColor(SDL_Color color);
};

#endif // MAP_H_INCLUDED
