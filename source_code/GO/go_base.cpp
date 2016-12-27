#include "go_base.h"

GO_Base::GO_Base()
{
    this->rect = { 0, 0, 0, 0 };
    this->clip_rect = { 0, 0, 0, 0 };
    this->texture = NULL;
    this->texture_type = TextureType::loaded;
}

GO_Base::~GO_Base()
{
    delete(&this->rect);
    delete(&this->clip_rect);

    if( this->texture_type == TextureType::loaded ) { SDL_DestroyTexture(this->texture); }
    else { this->texture = NULL; }
}

void GO_Base::SetTexture(SDL_Texture *texture)
{
    this->texture = texture;
    this->texture_type = TextureType::linked;
    this->rect.w = get_last_created_texture_width();
    this->rect.h = get_last_created_texture_height();
}

void GO_Base::SetTexture(string texture_path)
{
    this->texture = CreateTexture(texture_path);
    this->texture_type = TextureType::loaded;
    this->rect.w = get_last_created_texture_width();
    this->rect.h = get_last_created_texture_height();
}

void GO_Base::Render()
{
    SDL_RenderCopy(System::Renderer, this->texture, NULL, &this->rect);
}

void GO_Base::RenderFrame()
{
    SDL_RenderCopy(System::Renderer, this->texture, &this->clip_rect, &this->rect);
}

void GO_Base::SetX(int x)          { this->rect.x = x; }
void GO_Base::SetY(int y)          { this->rect.y = y; }
void GO_Base::SetWidth(int width)  { this->rect.w = width; }
void GO_Base::SetHeight(int height){ this->rect.h = height; }

void GO_Base::SetFrameX(int x)          { this->clip_rect.x = x; }
void GO_Base::SetFrameY(int y)          { this->clip_rect.y = y; }
void GO_Base::SetFrameWidth(int width)  { this->clip_rect.w = width; }
void GO_Base::SetFrameHeight(int height){ this->clip_rect.h = height; }

int GO_Base::GetX()        { return this->rect.x; }
int GO_Base::GetY()        { return this->rect.y; }
int GO_Base::GetWidth()    { return this->rect.w; }
int GO_Base::GetHeight()   { return this->rect.h; }

int GO_Base::GetFrameX()        { return this->clip_rect.x; }
int GO_Base::GetFrameY()        { return this->clip_rect.y; }
int GO_Base::GetFrameWidth()    { return this->clip_rect.w; }
int GO_Base::GetFrameHeight()   { return this->clip_rect.h; }
