#include "animation.h"

Animation::Animation()
{
    this->is_finished = false;
    this->frames = 0;
    this->current_frame = 1;
    this->fps = 0.0;
    this->frame_width = 0;
    this->time_for_frame = 0;
    this->last_time_updated = 0;
}

void Animation::Create(string path, int frames, double fps, AnimationType type)
{
    this->SetTexture(path);
    this->type = type;
    this->fps = fps;
    this->time_for_frame = 1000.0 / fps;
    this->last_time_updated = SDL_GetTicks();
    this->frame_width = this->GetWidth() / frames;
    this->Clip( 0, 0, this->frame_width, this->GetHeight() );

    if( type == AnimationType::Loop )       { this->frames = frames; }
    else if( type == AnimationType::GoBack ){ this->frames = ( frames * 2 ) - 2; }
    this->middle_frame = ( this->frames / 2 ) + 1;
}

void Animation::PlayNextFrame()
{
    //If it is time to take the next frame JUST DO IT!
    if( SDL_GetTicks() - this->last_time_updated >= this->time_for_frame )
    {
        this->ClipCurrentFrame();
        this->is_finished = false;

        this->current_frame++;
        if( this->current_frame == this->frames )
        {
            this->is_finished = true;
            this->current_frame = 0;
        }

        this->last_time_updated = SDL_GetTicks();
    }

    this->Render();
}

void Animation::ClipCurrentFrame()
{
    if( !this->is_finished )
    {
        if( this->type == AnimationType::GoBack )
        {
            if( this->current_frame < this->middle_frame )
            {
                this->SetClipX( this->GetClipX() + this->frame_width );
            }
            else
            {
                this->SetClipX( this->GetClipX() - this->frame_width );
            }
        }
        else if( this->type == AnimationType::Loop )
        {
            this->SetClipX( this->GetClipX() + this->frame_width );
        }
    }
    else
    {
        this->SetClipX(0);
    }
}

bool Animation::IsFinished() { return this->is_finished; }
