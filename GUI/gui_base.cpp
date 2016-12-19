#include "gui_base.h"

GUI_Base::GUI_Base()
{
    this->rect = { 0, 0, 0, 0 };
    this->texture = NULL;
}

GUI_Base::~GUI_Base()
{
    delete(&this->rect);
    SDL_DestroyTexture(this->texture);
}

void GUI_Base::Render()
{
    SDL_RenderCopy(System::Renderer, this->texture, NULL, &this->rect);
}

void GUI_Base::SetX(int x)          { this->rect.x = x; }
void GUI_Base::SetY(int y)          { this->rect.y = y; }
void GUI_Base::SetWidth(int width)  { this->rect.w = width; }
void GUI_Base::SetHeight(int height){ this->rect.h = height; }

int GUI_Base::GetX()        { return this->rect.x; }
int GUI_Base::GetY()        { return this->rect.y; }
int GUI_Base::GetWidth()    { return this->rect.w; }
int GUI_Base::GetHeight()   { return this->rect.h; }
