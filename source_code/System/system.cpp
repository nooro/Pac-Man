#include "system.h"

SDL_Renderer *System::Renderer = NULL;

bool System::Init()
{
    return System::InitSDL() & System::Window::Init() & System::CreateTheRenderer();
}

void System::Free()
{
    SDL_DestroyWindow(System::Window);
    SDL_DestroyRenderer(System::Renderer);
    SDL_Quit();
}

bool System::InitSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        Error::New(Error::Type::SDL, "Can not initialize SDL");
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
