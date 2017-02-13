#include "text.h"

Text::Text()
{
    this->text = "";
    this->color = {255, 0, 0, 0};
    this->font = NULL;
}

Text::~Text()
{
    delete(&this->color);
    delete(&this->text);
}

bool Text::Create(string text, TTF_Font *font, SDL_Color color)
{
    this->text = text;
    this->color = color;
    this->font = font;

    return this->Init();
}

void Text::SetText(string text)
{
    this->text = text;
    this->Init();
}

void Text::SetColor(SDL_Color color)
{
    if(this->color.r != color.r && this->color.g != color.g && this->color.b != color.b)
    {
        this->color = color;
        this->Init();
    }
}
void Text::SetColor(int r, int g, int b)
{
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->Init();
}

void Text::SetFont(TTF_Font *font) { this->font = font; }
void Text::SetFont(string path)
{
    this->font = NULL;
    this->font = TTF_OpenFont(path.c_str(), 28);
    if(this->font == NULL)
    {
        Error::New(Error::Type::TTF, "Could not set text font");
    }
    this->Init();
}

bool Text::Init()
{
    SDL_Surface *textSurface = NULL;
    textSurface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
    if(textSurface == NULL)
    {
        Error::New(Error::Type::SDL, "Can not make text surface for the following text: \n\'" + this->text + "\'");
        return false;
    }

    this->texture = NULL;
    this->texture = SDL_CreateTextureFromSurface(System::Renderer, textSurface);
    if(this->texture == NULL)
    {
        Error::New(Error::Type::SDL, "Can not make text texture for the following text: \n\'" + this->text + "\'");
        return false;
    }

    this->rect.w = textSurface->w;
    this->rect.h = textSurface->h;

    SDL_FreeSurface(textSurface);
    return true;
}
