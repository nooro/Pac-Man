#ifndef ERROR_MANAGER_H_INCLUDED
#define ERROR_MANAGER_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>

class Error
{
    public:
        enum Type
        {
            SDL,
            IMG,
            TTF,
            MIX,
            Custom
        };

        static void New(Error::Type type, std::string message);

    private:
        static const SDL_MessageBoxButtonData buttons[1];
};

#endif // ERROR_MANAGER_H_INCLUDED
