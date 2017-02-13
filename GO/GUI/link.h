#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

#include "text.h"

class Link : public Text
{
    public:
        Link();
        bool IsHovered();
        bool IsClicked(SDL_Event &event);

    private:
        int mouse_x, mouse_y;
        bool click;
};

#endif // LINK_H_INCLUDED
