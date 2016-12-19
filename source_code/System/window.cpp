#include "system.h"

SDL_Window *System::Window = NULL;
int System::Window::height;
int System::Window::width;

bool System::Window::Init()
{
    System::Window = SDL_CreateWindow(  "Pac-Man",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        0,
                                        0,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);

    if(System::Window == NULL)
    {
        Error::New(Error::Type::SDL, "Can not create the window");
        return false;
    }

    SDL_DisplayMode display_variables;
    if( SDL_GetCurrentDisplayMode(0, &display_variables) != 0)
    {
        Error::New(Error::Type::SDL, "Can not get the display's variables");
        return false;
    }

    System::Window::width = display_variables.w;
    System::Window::height = display_variables.h;

    delete(&display_variables);

    return true;
}

int System::Window::GetWidth() { return System::Window::width; }
int System::Window::GetHeight(){ return System::Window::height; }

void System::Window::Clear() { SDL_RenderClear(System::Renderer); }
void System::Window::Update(){ SDL_RenderPresent(System::Renderer); }
