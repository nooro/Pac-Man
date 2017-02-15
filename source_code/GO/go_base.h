#ifndef GUI_BASE_H_INCLUDED
#define GUI_BASE_H_INCLUDED

#include "../System/system.h"

SDL_Texture *CreateTexture(string texture_path);
int get_last_created_texture_width();
int get_last_created_texture_height();

class GO_Base
{
    public:
        GO_Base();
        ~GO_Base();

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

        SDL_Texture *texture;
        SDL_Rect rect;

    private:

        enum TextureType { loaded, linked };
        TextureType texture_type;
};

#endif // GUI_BASE_H_INCLUDED
