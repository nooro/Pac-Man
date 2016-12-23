#include "gui_base.h"

int last_created_texture_width;
int last_created_texture_height;

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

    last_created_texture_height = surface->h;
    last_created_texture_width = surface->w;

    SDL_FreeSurface(surface);

    return texture;
}

int get_last_created_texture_width() { return last_created_texture_width; }
int get_last_created_texture_height() { return last_created_texture_height; }
