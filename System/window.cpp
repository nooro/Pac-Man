#include "system.h"

SDL_Window *System::Window = NULL;
int System::Window::height;
int System::Window::width;

bool System::Window::Init()
{
    System::Window = SDL_CreateWindow(  "PacMan",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        0,
                                        0,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP );

    if(System::Window == NULL)
    {
        ///error
        return false;
    }

    SDL_DisplayMode current_display;
    if( SDL_GetCurrentDisplayMode(0, &current_display) != 0)
    {
        ///error
        return false;
    }
    System::Window::width = current_display.w;
    System::Window::height = current_display.h;

    delete(&current_display);
    return true;
}

int System::Window::GetWidth() { return System::Window::width; }
int System::Window::GetHeight(){ return System::Window::height; }

void System::Window::Clear() { SDL_RenderClear(System::Renderer); }
void System::Window::Update(){ SDL_RenderPresent(System::Renderer); }
