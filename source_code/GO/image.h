#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include "go_base.h"

class Image : public GO_Base
{
    public:
        Image();
        Image(string path);
        ~Image();

        void Render();

        void Clip(int x, int y, int w, int h);
        void Rotate( double angle );
        void FlipHorizontal();
        void FlipVertical();

        void SetClipX(int x);
        void SetClipY(int y);
        void SetClipWidth(int width);
        void SetClipHeight(int height);

        int GetClipX();
        int GetClipY();
        int GetClipWidth();
        int GetClipHeight();

    private:
        void Init();

        SDL_RendererFlip flip_type;
        SDL_RendererFlip rotation;

        double rotation_angle;

        SDL_Rect clip_rect;
        bool is_clipped;
};

#endif // IMAGE_H_INCLUDED
