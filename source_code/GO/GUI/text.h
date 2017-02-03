#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "../go_base.h"

class Text : public GO_Base
{
    public:
        Text(string text, TTF_Font *font, SDL_Color color);
        void SetText(string text);

        void SetColor(SDL_Color color);
        void SetColor(int r, int g, int b);

        void SetFont(TTF_Font *font);
        void SetFont(string path);

    private:
        bool Init();
        TTF_Font *font;
        SDL_Color color;
        string text;
};

#endif // TEXT_H_INCLUDED
