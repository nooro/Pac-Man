#include "gui_base.h"

GUI_Base::GUI_Base()
{
    this->rect = { 0, 0, 0, 0 };
    this->clip_rect = { 0, 0, 0, 0 };
    this->texture = NULL;
    this->texture_type = TextureType::loaded;
}

GUI_Base::~GUI_Base()
{
    delete(&this->rect);
    delete(&this->clip_rect);

    if( this->texture_type == TextureType::loaded ) { SDL_DestroyTexture(this->texture); }
    else { this->texture = NULL; }
}

void GUI_Base::SetTexture(SDL_Texture *texture)
{
    this->texture = texture;
    this->texture_type = TextureType::linked;
    this->rect.w = get_last_created_texture_width();
    this->rect.h = get_last_created_texture_height();
}

void GUI_Base::SetTexture(string texture_path)
{
    this->texture = CreateTexture(texture_path);
    this->texture_type = TextureType::loaded;
    this->rect.w = get_last_created_texture_width();
    this->rect.h = get_last_created_texture_height();
}

void GUI_Base::Render()
{
    SDL_RenderCopy(System::Renderer, this->texture, NULL, &this->rect);
}

void GUI_Base::RenderFrame()
{
    SDL_RenderCopy(System::Renderer, this->texture, &this->clip_rect, &this->rect);
}

void GUI_Base::SetX(int x)          { this->rect.x = x; }
void GUI_Base::SetY(int y)          { this->rect.y = y; }
void GUI_Base::SetWidth(int width)  { this->rect.w = width; }
void GUI_Base::SetHeight(int height){ this->rect.h = height; }

void GUI_Base::SetFrameX(int x)          { this->clip_rect.x = x; }
void GUI_Base::SetFrameY(int y)          { this->clip_rect.y = y; }
void GUI_Base::SetFrameWidth(int width)  { this->clip_rect.w = width; }
void GUI_Base::SetFrameHeight(int height){ this->clip_rect.h = height; }


int GUI_Base::GetX()        { return this->rect.x; }
int GUI_Base::GetY()        { return this->rect.y; }
int GUI_Base::GetWidth()    { return this->rect.w; }
int GUI_Base::GetHeight()   { return this->rect.h; }

int GUI_Base::GetFrameX()        { return this->clip_rect.x; }
int GUI_Base::GetFrameY()        { return this->clip_rect.y; }
int GUI_Base::GetFrameWidth()    { return this->clip_rect.w; }
int GUI_Base::GetFrameHeight()   { return this->clip_rect.h; }
