#include "pac_man.h"

Image PacMan::idle_image;
Animation PacMan::walk_animation;
Animation PacMan::die_animation;

bool PacMan::is_walking;
bool PacMan::is_alive;
int PacMan::lives;

SDL_Rect PacMan::rect;

bool PacMan::Init()
{
    PacMan::idle_image.SetTexture( PAC_MAN_IDLE_IMAGE );
    if( PacMan::idle_image.texture == NULL ) { return false; }

    PacMan::walk_animation.Create( PAC_MAN_WALK_ANIMATION, 3, 6, AnimationType::GoBack );
    if( PacMan::walk_animation.texture == NULL ) { return false; }

    PacMan::die_animation.Create( PAC_MAN_DIE_ANIMATION, 14, 7, AnimationType::Loop );
    if( PacMan::die_animation.texture == NULL ) { return false; }

    PacMan::is_alive = true;
    PacMan::is_walking = false;
    PacMan::lives = 3;

    PacMan::rect.w = System::Window::GetWidth() / 20;
    PacMan::rect.h = PacMan::rect.w;
    PacMan::rect.x = System::Window::GetWidth() / 2 - PacMan::rect.w;
    PacMan::rect.y = System::Window::GetHeight() / 2 - PacMan::rect.h;

    PacMan::die_animation.rect = PacMan::rect;
    PacMan::walk_animation.rect = PacMan::rect;
    PacMan::idle_image.rect = PacMan::rect;

    return true;
}

void PacMan::Render()
{
    PacMan::die_animation.PlayNextFrame();
}
