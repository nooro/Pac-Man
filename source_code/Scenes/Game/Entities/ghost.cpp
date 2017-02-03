#include "ghost.h"

bool Ghost::Init(int hight, int width)
{
    this->is_alive = true;
    this->is_walking = true;

    this->rect.w = width;
    this->rect.h = hight;
    this->movement_speed = this->rect.w / 6;

    this->idle_image.SetTexture( GHOST_IDLE_IMAGE );
    if( this->idle_image.texture == NULL ) { return false; }

    this->walk_animation.Create( GHOST_WALK_ANIMATION, 3, movement_speed * 3 , AnimationType::GoBack );
    if( this->walk_animation.texture == NULL ) { return false; }

    this->walk_animation.rect = this->rect;
    this->idle_image.rect = this->rect;

    this->walk_direction = General::Direction::Right;

    return true;
}

void Ghost::Update()
{
    this->Move();
}

void Ghost::Move()
{
    if( this->is_walking )
    {
        if( this->walk_direction == General::Direction::Right )
            { this->rect.x += this->movement_speed; }

        else if( this->walk_direction == General::Direction::Left )
            { this->rect.x -= this->movement_speed; }

        else if( this->walk_direction == General::Direction::Up )
            { this->rect.y -= this->movement_speed; }

        else if( this->walk_direction == General::Direction::Down )
            { this->rect.y += this->movement_speed; }

        this->walk_animation.rect.x = this->rect.x;
        this->walk_animation.rect.y = this->rect.y;
    }
}

void Ghost::Die()
{

}

void Ghost::Render()
{
    if(this->is_walking)
    {
        this->walk_animation.PlayNextFrame();
    }
    else
    {
        this->idle_image.Render();
    }
}

int Ghost::GetX() { return this->rect.x; }
int Ghost::GetY() { return this->rect.y; }
int Ghost::GetWidth() { return this->rect.w; }
int Ghost::GetHeight() { return this->rect.h; }

void Ghost::SetMovementSpeed(int speed)
{
    this->movement_speed = speed;
}

int Ghost::GetMovementSpeed()
{
    return this->movement_speed;
}
