#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../../System/system.h"
#include "Entities/pac_man.h"

#include "game_panel.h"
#include "Map/map.h"

class GameScene
{
    public:
        static bool Init();
        static void Play();

    private:
        static void GetPlayerInput();
        static void CheckForCollisionWithWall();
        static void CheckForCollisionWithPoint();
        static void Render();

        static bool is_active;

        static Map current_map;
};

#endif // GAME_H_INCLUDED
