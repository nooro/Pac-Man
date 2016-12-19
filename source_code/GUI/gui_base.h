#ifndef GUI_BASE_H_INCLUDED
#define GUI_BASE_H_INCLUDED

#include "../System/system.h"

SDL_Texture *CreateTexture(string texture_path);

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

        void SetTexture(SDL_Texture *texture);
        void SetTexture(string texture_path);

        void Render();

    private:
        SDL_Rect rect;
        SDL_Rect *clip_rect;

        SDL_Texture *texture;
        enum TextureType
        {
            loaded,
            linked
        };
        TextureType texture_type;
};

#endif // GUI_BASE_H_INCLUDED
