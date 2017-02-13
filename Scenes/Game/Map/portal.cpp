#include "portal.h"

SDL_Texture *Portal::texture;
SDL_Color Portal::color;
SDL_Rect Portal::entrances[2];
int Portal::number_of_entrances;

void  Portal::SetColor(SDL_Color color)
{
    SDL_SetTextureColorMod(Portal::texture, color.r, color.g, color.b);
}

bool Portal::Add(SDL_Rect first_rect, SDL_Rect second_rect)
{
    Portal::texture = NULL;
    Portal::texture = CreateTexture(PORTAL_IMAGE);
    if( Portal::texture == NULL )
    {
        Error::New(Error::Type::IMG, "Could not create the portal texture");
        return false;
    }

    Portal::entrances[0] = first_rect;
    Portal::entrances[1] = second_rect;
    return true;
}

void Portal::Render()
{
    SDL_RenderCopy(System::Renderer, Portal::texture, NULL, &Portal::entrances[0]);
    SDL_RenderCopy(System::Renderer, Portal::texture, NULL, &Portal::entrances[1]);
}

void Portal::Free()
{
    SDL_DestroyTexture(Portal::texture);
    delete(&Portal::color);
    delete(&Portal::entrances);
}
