#ifndef GUI_BASE_H_INCLUDED
#define GUI_BASE_H_INCLUDED

#include "../System/system.h"

SDL_Texture *CreateTexture(string texture_path);
int get_last_created_texture_width();
int get_last_created_texture_height();

class GUI_Base
{
    public:
        GUI_Base();
        ~GUI_Base();

        void SetX(int x);           void SetFrameX(int x);
        void SetY(int y);           void SetFrameY(int y);
        void SetWidth(int width);   void SetFrameWidth(int width);
        void SetHeight(int height); void SetFrameHeight(int height);

        int GetX();         int GetFrameX();
        int GetY();         int GetFrameY();
        int GetWidth();     int GetFrameWidth();
        int GetHeight();    int GetFrameHeight();

        void SetTexture(SDL_Texture *texture);
        void SetTexture(string texture_path);

        void Render();
        void RenderFrame();

    private:
        SDL_Rect rect;
        SDL_Rect clip_rect;

        SDL_Texture *texture;
        enum TextureType
        {
            loaded,
            linked
        };
        TextureType texture_type;
};

#endif // GUI_BASE_H_INCLUDED
