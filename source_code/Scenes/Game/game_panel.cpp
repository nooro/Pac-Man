#include "game_panel.h"

SDL_Rect GamePanel::rect;

void GamePanel::Init()
{
    //Calculate the resolution for the game panel (5:4)
    GamePanel::rect.h = System::Window::GetHeight();
    GamePanel::rect.w = System::Window::GetHeight() + ( System::Window::GetHeight() / 4 );

    //Center the game panel
    GamePanel::rect.x = ( System::Window::GetWidth() / 2 ) - ( GamePanel::rect.w / 2 ) ;
    GamePanel::rect.y = 0;
}

int GamePanel::GetWidth()  { return GamePanel::rect.w; }
int GamePanel::GetHeight() { return GamePanel::rect.h; }
int GamePanel::GetX()      { return GamePanel::rect.x; }
int GamePanel::GetY()      { return GamePanel::rect.y; }
