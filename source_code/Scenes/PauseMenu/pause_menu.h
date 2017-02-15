#ifndef PAUSE_MENU_H_INCLUDED
#define PAUSE_MENU_H_INCLUDED

#include "../../System/system.h"
#include "../../GO/go.h"
#include "../MainMenu/main_menu.h"
#include "../Game/game.h"

class PauseMenu
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

        static TTF_Font *options_font;
        static Link options[];
        static int selected_option;
};


#endif // PAUSE_MENU_H_INCLUDED
