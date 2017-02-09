#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../../System/system.h"

#include "Entities/pac_man.h"
#include "Entities/ghost.h"

#include "game_panel.h"
#include "Map/map.h"
#include "../MainMenu/main_menu.h"

class GameScene
{
    public:
        static bool Init();
        static void Free();
        static void Play();

    private:
        static void GetPlayerInput();
        static void CheckForCollision();

        static bool CheckForCollisionWithWall();
        static bool CheckForCollisionWithPoint();
        static bool CheckForCollisionWithBonusPoint();

        static void Render();

        static bool is_active;

        static Map current_map;

        static TTF_Font *stats_font;

        static int score;
        static Text score_text;
        static Text lives_text;
};

#endif // GAME_H_INCLUDED
