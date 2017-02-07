#include "main_menu.h"

bool MainMenu::is_active;
Image MainMenu::logo_image;

bool MainMenu::Init()
{
    MainMenu::logo_image.SetTexture(LOGO_IMAGE);
    MainMenu::logo_image.SetHeight(MainMenu::logo_image.GetHeight()/(MainMenu::logo_image.GetWidth()/(System::Window::GetWidth()/4)));
    MainMenu::logo_image.SetWidth(System::Window::GetWidth() / 4);
    MainMenu::logo_image.SetX( (System::Window::GetWidth() / 2) - (MainMenu::logo_image.GetWidth() / 2) );
    MainMenu::logo_image.SetY( System::Window::GetHeight() / 10 );

    MainMenu::is_active = false;
    return true;
}

void MainMenu::Play()
{
    MainMenu::is_active = true;

    while( MainMenu::is_active )
    {
        MainMenu::Render();
    }
}

void MainMenu::Render()
{
    System::Window::Clear();

    MainMenu::logo_image.Render();

    System::Window::Update();
}
