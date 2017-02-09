#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED

#include "../../System/system.h"
#include "../Game/game.h"
#include "../../GO/go.h"

class MainMenu
{
    public:
        static bool Init();
        static void Free();
        static void Play();

    private:
        static bool is_active;

        static void Render();

        static SDL_Event event;
        static bool CheckForEvents();

        static Image logo_image;

        static TTF_Font *options_font;
        static Link options[];
        static int selected_option;
};

#endif // MAIN_MENU_H_INCLUDED
