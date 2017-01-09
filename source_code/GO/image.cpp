#include "image.h"

Image::Image()
{
    this->Init();
}

Image::Image(string path)
{
    this->Init();
    this->SetTexture(path);
}

void Image::Init()
{
    this->clip_rect = { 0, 0, 0, 0 };
    this->is_clipped = false;
    this->flip_type = SDL_FLIP_NONE;
    this->rotation = SDL_FLIP_HORIZONTAL;
    this->rotation_angle = 0.0;
}

Image::~Image()
{
    delete(&this->clip_rect);
}

void Image::Render()
{
    if( !this->is_clipped )
    {
        if( this->flip_type == SDL_FLIP_NONE && ( this->rotation_angle == 0 || this->rotation_angle == 360 ) )
        {
            SDL_RenderCopy(System::Renderer, this->texture, NULL, &this->rect);
        }
        else
        {
            if( this->flip_type != SDL_FLIP_NONE )
            {
                SDL_RenderCopyEx(System::Renderer, this->texture, NULL, &this->rect, 180, NULL, this->flip_type);
            }
            else
            {
                SDL_RenderCopyEx(System::Renderer, this->texture, NULL, &this->rect, this->rotation_angle, NULL, this->rotation);
            }
        }
    }
    else
    {
        if( this->flip_type == SDL_FLIP_NONE && ( this->rotation_angle == 0 || this->rotation_angle == 360 ) )
        {
            SDL_RenderCopy(System::Renderer, this->texture, &this->clip_rect, &this->rect);
        }
        else
        {
            if( this->flip_type != SDL_FLIP_NONE )
            {
                SDL_RenderCopyEx(System::Renderer, this->texture, &this->clip_rect, &this->rect, 180, NULL, this->flip_type);
            }
            else
            {
                SDL_RenderCopyEx(System::Renderer, this->texture, &this->clip_rect, &this->rect, this->rotation_angle, NULL, this->rotation);
            }
        }
    }
}

void Image::Clip(int x, int y, int w, int h)
{
    this->clip_rect.x = x;
    this->clip_rect.y = y;
    this->clip_rect.w = w;
    this->clip_rect.h = h;
    this->rect.w = w;
    this->rect.h = h;
    this->is_clipped = true;
}
void Image::SetClipX(int x)
{
    this->clip_rect.x = x;
    this->is_clipped = true;
}
void Image::SetClipY(int y)
{
    this->clip_rect.y = y;
    this->is_clipped = true;
}
void Image::SetClipWidth(int width)
{
    this->clip_rect.w = width;
    this->rect.w = width;
    this->is_clipped = true;
}
void Image::SetClipHeight(int height)
{
    this->clip_rect.h = height;
    this->rect.h = height;
    this->is_clipped = true;
}

void Image::Rotate( double angle )
{
    this->rotation_angle = angle;
    this->flip_type = SDL_FLIP_NONE;
}

void Image::FlipHorizontal()
{
    if( this->flip_type == SDL_FLIP_HORIZONTAL )
    {
        this->flip_type = SDL_FLIP_NONE;
    }
    else
    {
        this->flip_type = SDL_FLIP_HORIZONTAL;
    }
    this->rotation_angle = 0;
}

void Image::FlipVertical()
{
    if( this->flip_type == SDL_FLIP_VERTICAL )
    {
        this->flip_type = SDL_FLIP_NONE;
    }
    else
    {
        this->flip_type = SDL_FLIP_VERTICAL;
    }
    this->rotation_angle = 0;
}

int Image::GetClipX()       { return this->clip_rect.x; }
int Image::GetClipY()       { return this->clip_rect.y; }
int Image::GetClipWidth()   { return this->clip_rect.w; }
int Image::GetClipHeight()  { return this->clip_rect.h; }
