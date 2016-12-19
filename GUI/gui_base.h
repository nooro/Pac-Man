#ifndef GUI_BASE_H_INCLUDED
#define GUI_BASE_H_INCLUDED

#include "../System/system.h"

class GUI_Base
{
    public:
        GUI_Base();
        ~GUI_Base();

        void SetX(int x);
        void SetY(int y);
        void SetWidth(int width);
        void SetHeight(int height);

        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();

        void Render();

    private:
        SDL_Rect rect;
        SDL_Texture *texture;
};

#endif // GUI_BASE_H_INCLUDED
