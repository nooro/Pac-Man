#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

#include "text.h"

class Link : Text
{
    public:
        Link();
        bool IsHovered();
        bool IsClicked();

    private:
        int mouse_x, mouse_y;
        bool click;
        SDL_Event event;
};

#endif // LINK_H_INCLUDED
