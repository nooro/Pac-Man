#include "link.h"

Link::Link()
{
    SDL_GetMouseState(&mouse_x, &mouse_y);
    this->click = false;
}

bool Link::IsClicked()
{
    this->click = false;
    if( this->event.type == SDL_MOUSEBUTTONUP )
    {
        if( this->event.button.button == SDL_BUTTON_LEFT )
        {
            if( this->click == false )
            {
                click = true;
                return this->IsHovered();
            }
        }
    }
    return false;
}

bool Link::IsHovered()
{
    SDL_GetMouseState(&mouse_x, &mouse_y);
    return  this->mouse_x >= this->rect.x
            && this->mouse_x <= this->rect.x + this->rect.w
            && mouse_y >= rect.y
            && mouse_y <= rect.y + rect.h ;
}
