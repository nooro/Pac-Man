#ifndef MAIN_MENU_H_INCLUDED
#define MAIN_MENU_H_INCLUDED

#include "../../System/system.h"
#include "../../GO/go.h"

class MainMenu
{
    public:
        static bool Init();
        static void Play();

    private:
        static bool is_active;

        static void Render();

        static Image logo_image;
};

#endif // MAIN_MENU_H_INCLUDED
