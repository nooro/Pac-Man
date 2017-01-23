#include "pac_man.h"

Image PacMan::idle_image;
Animation PacMan::walk_animation;
Animation PacMan::die_animation;

bool PacMan::is_walking;
bool PacMan::is_alive;
int PacMan::lives;
int PacMan::movement_speed;

SDL_Rect PacMan::rect;
PacMan::Direction PacMan::walk_direction;

bool PacMan::Init()
{
    PacMan::rect.h = GamePanel::GetHeight() / 40;
    PacMan::rect.w = PacMan::rect.h;
    PacMan::rect.x = System::Window::GetWidth() / 2 - PacMan::rect.w;
    PacMan::rect.y = System::Window::GetHeight() / 2 - PacMan::rect.h;

    PacMan::is_alive = true;
    PacMan::is_walking = true;
    PacMan::lives = 3;
    PacMan::movement_speed = PacMan::rect.w / 6;

    PacMan::idle_image.SetTexture( PAC_MAN_IDLE_IMAGE );
    if( PacMan::idle_image.texture == NULL ) { return false; }

    PacMan::walk_animation.Create( PAC_MAN_WALK_ANIMATION, 3, movement_speed * 3 , AnimationType::GoBack );
    if( PacMan::walk_animation.texture == NULL ) { return false; }

    PacMan::die_animation.Create( PAC_MAN_DIE_ANIMATION, 14, 7, AnimationType::Loop );
    if( PacMan::die_animation.texture == NULL ) { return false; }

    PacMan::die_animation.rect = PacMan::rect;
    PacMan::walk_animation.rect = PacMan::rect;
    PacMan::idle_image.rect = PacMan::rect;

    PacMan::walk_direction = Direction::Right;

    return true;
}

bool PacMan::IsAlive()   { return PacMan::is_alive; }
bool PacMan::IsWalking() { return PacMan::is_walking; }

void PacMan::Update()
{
    PacMan::Move();

    PacMan::walk_animation.rect.x = PacMan::rect.x;
    PacMan::walk_animation.rect.y = PacMan::rect.y;
}

void PacMan::Move()
{
    if( PacMan::is_walking )
    {
        if( PacMan::walk_direction == PacMan::Direction::Right )
            { PacMan::rect.x += PacMan::movement_speed; }

        else if( PacMan::walk_direction == PacMan::Direction::Left )
            { PacMan::rect.x -= PacMan::movement_speed; }

        else if( PacMan::walk_direction == PacMan::Direction::Up )
            { PacMan::rect.y -= PacMan::movement_speed; }

        else if( PacMan::walk_direction == PacMan::Direction::Down )
            { PacMan::rect.y += PacMan::movement_speed; }
    }
}

void PacMan::Die()
{
    PacMan::is_alive = false;
    PacMan::is_walking = false;

    PacMan::die_animation.rect.x = PacMan::rect.x;
    PacMan::die_animation.rect.y = PacMan::rect.y;

    PacMan::die_animation.Reset();
    PacMan::die_animation.Rotate( PacMan::walk_direction );
}

void PacMan::StopWalking()
{
    PacMan::is_walking = false;

    PacMan::idle_image.rect.x = PacMan::rect.x;
    PacMan::idle_image.rect.y = PacMan::rect.y;
}

void PacMan::StartWalking()
{
    PacMan::is_walking = true;

    PacMan::walk_animation.rect.x = PacMan::rect.x;
    PacMan::walk_animation.rect.y = PacMan::rect.y;
}

void PacMan::ChangeWalkDirection( Direction direction )
{
    if( PacMan::walk_direction != direction )
    {
        PacMan::walk_direction = direction;
        PacMan::idle_image.Rotate(direction);
        PacMan::walk_animation.Rotate(direction);
    }
}

void PacMan::Render()
{
    if(PacMan::is_alive)
    {
        if(PacMan::is_walking)
        {
            PacMan::walk_animation.PlayNextFrame();
        }
        else
        {
            PacMan::idle_image.Render();
        }
    }
    else
    {
        PacMan::die_animation.PlayNextFrame();
    }
}

int PacMan::GetX() { return PacMan::rect.x; }
int PacMan::GetY() { return PacMan::rect.y; }
int PacMan::GetWidth() { return PacMan::rect.w; }
int PacMan::GetHeight() { return PacMan::rect.h; }

void PacMan::SetX(int x) { PacMan::rect.x = x; }
void PacMan::SetY(int y) { PacMan::rect.y = y; }
void PacMan::SetWidth(int w) { PacMan::rect.w = w; }
void PacMan::SetHeight(int h) { PacMan::rect.h = h; }
