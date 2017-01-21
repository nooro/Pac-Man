#include "genereal.h"

bool General::random_is_seed = false;

SDL_Color General::Colors[6] =
{
    {63, 72, 204, 255},     //BLUE
    {0, 128, 0, 255},       //GREEN
    {255, 128, 0, 255},     //ORANGE
    {64, 0, 64, 255},       //PURPLE
    {155, 0, 0, 255},       //RED
    {255, 255, 255, 255}    //WHITE
};


int General::RandomNumber(int min, int max)
{
    if ( !General::random_is_seed )
    {
        srand(time(NULL));
        General::random_is_seed = true;
    }
    return min + rand() % (max - min + 1);
}
