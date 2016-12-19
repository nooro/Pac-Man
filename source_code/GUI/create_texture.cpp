#include "gui_base.h"

SDL_Texture *CreateTexture(string texture_path)
{
    SDL_Surface *surface = NULL;
    surface = IMG_Load( texture_path.c_str() );
    if(surface == NULL)
    {
        Error::New(Error::Type::IMG, "Can not load the texture");
        SDL_FreeSurface(surface);
        return NULL;
    }

    SDL_Texture *texture = NULL;
    texture = SDL_CreateTextureFromSurface(System::Renderer, surface);
    if(texture == NULL)
    {
        Error::New(Error::Type::IMG, "Can not load the texture");
        SDL_FreeSurface(surface);
        return NULL;
    }

    SDL_FreeSurface(surface);

    return texture;
}
