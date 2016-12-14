#include "system.h"

SDL_Renderer *System::Renderer = NULL;

bool System::Init()
{
    return System::InitSDL() & System::Window::Init();
}

void System::Free()
{
    SDL_DestroyWindow(System::Window);
    SDL_DestroyRenderer(System::Renderer);
}

bool System::InitSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        ///error
        return false;
    }
    return true;
}
