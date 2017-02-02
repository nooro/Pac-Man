#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#include "../../../System/system.h"
#include "../../../GO/go.h"

class Ghost
{
    public:
        bool Init(int high, int width);
        void Render();

        void Update();

        enum Direction { Right, Left, Up = 90, Down = 270 };
        Direction walk_direction;

        void Die();

        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();

        void SetMovementSpeed(int speed);
        int GetMovementSpeed();

    private:
        void Move();

        SDL_Rect rect;

        bool is_alive, is_walking;
        int movement_speed;

        Image idle_image;
        Animation walk_animation;
};

#endif // GHOST_H_INCLUDED
