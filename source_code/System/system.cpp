#include "system.h"

SDL_Renderer *System::Renderer = NULL;

bool System::Init()
{
    return System::InitSDL() && System::Window::Init() && System::CreateTheRenderer();
}

void System::Free()
{
    SDL_DestroyRenderer(System::Renderer);
    SDL_DestroyWindow(System::Window);

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool System::InitSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Error::New(Error::Type::SDL, "Can not initialize SDL");
        return false;
    }

    int image_flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int is_initted = IMG_Init( image_flags );
    if( ( is_initted & image_flags ) != image_flags)
    {
        Error::New(Error::Type::IMG, "Can not initialize SDL_image");
        return false;
    }

    if(TTF_Init() != 0)
    {
        Error::New(Error::Type::TTF, "Can not initialize SDL_ttf");
        return false;
    }

    if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) < 0)
    {
        Error::New(Error::Type::MIX, "Can not initialize SDL_mixer");
        return false;
    }
    return true;
}

bool System::CreateTheRenderer()
{
    System::Renderer = SDL_CreateRenderer(System::Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(System::Renderer == NULL)
    {
        Error::New(Error::Type::SDL, "Can not create the renderer");
        return false;
    }
    return true;
}
