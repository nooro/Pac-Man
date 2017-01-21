#ifndef PAC_MAN_H_INCLUDED
#define PAC_MAN_H_INCLUDED

#include "../../../System/system.h"
#include "../game_panel.h"
#include "../../../GO/go.h"

class PacMan
{
    public:
        static bool Init();
        static void Render();

        static void Update();

        enum Direction { Right, Left, Up = 90, Down = 270 };
        static Direction walk_direction;
        static void ChangeWalkDirection(PacMan::Direction direction);

        static bool IsWalking();
        static bool IsAlive();

        static void Die();
        static void StopWalking();
        static void StartWalking();

        static int GetX();
        static int GetY();
        static int GetWidth();
        static int GetHeight();

    private:
        static void Move();

        static SDL_Rect rect;

        static bool is_alive, is_walking;
        static int lives;
        static int movement_speed;

        static Image idle_image;
        static Animation die_animation;
        static Animation walk_animation;
};

#endif // PAC_MAN_H_INCLUDED
