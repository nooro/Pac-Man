#include "main_menu.h"

bool MainMenu::is_active;
Image MainMenu::logo_image;

TTF_Font *MainMenu::options_font;
Link MainMenu::play_option;
Link MainMenu::quit_option;
int MainMenu::selected_option;

bool MainMenu::Init()
{
    MainMenu::logo_image.SetTexture(LOGO_IMAGE);
    MainMenu::logo_image.SetHeight(MainMenu::logo_image.GetHeight()/(MainMenu::logo_image.GetWidth()/(System::Window::GetWidth()/3)));
    MainMenu::logo_image.SetWidth(System::Window::GetWidth() / 3);
    MainMenu::logo_image.SetX( (System::Window::GetWidth() / 2) - (MainMenu::logo_image.GetWidth() / 2) );
    MainMenu::logo_image.SetY( System::Window::GetHeight() / 10 );

    MainMenu::options_font = NULL;
    MainMenu::options_font = TTF_OpenFont(FONT_BOING, 60);
    if(MainMenu::options_font == NULL)
    {
        Error::New(Error::Type::TTF, "Can not load main menu options font");
        return false;
    }

    if ( !MainMenu::play_option.Create("Play", MainMenu::options_font, WHITE) )
    {
        Error::New(Error::Type::TTF, "Could not create the play option text from the main menu");
        return false;
    }
    MainMenu::play_option.SetX( (System::Window::GetWidth() / 2) - (MainMenu::play_option.GetWidth() / 2) );
    MainMenu::play_option.SetY( MainMenu::logo_image.GetY() + MainMenu::logo_image.GetHeight() + ( System::Window::GetHeight() / 5 ) );

    if ( !MainMenu::quit_option.Create("Quit", MainMenu::options_font, WHITE) )
    {
        Error::New(Error::Type::TTF, "Could not create the quit option text from the main menu");
        return false;
    }
    MainMenu::quit_option.SetX( (System::Window::GetWidth() / 2) - (MainMenu::quit_option.GetWidth() / 2) );
    MainMenu::quit_option.SetY( MainMenu::play_option.GetY() + MainMenu::play_option.GetHeight() + 20 );

    MainMenu::selected_option = 0;

    MainMenu::is_active = false;

    return true;
}

void MainMenu::Free()
{
    delete(&MainMenu::logo_image);
    delete(&MainMenu::play_option);
    delete(&MainMenu::quit_option);
    TTF_CloseFont(MainMenu::options_font);
}

void MainMenu::Play()
{
    MainMenu::is_active = true;

    while( MainMenu::is_active )
    {
        MainMenu::CheckForEvents();
        MainMenu::Render();
    }
}

SDL_Event MainMenu::event;
void MainMenu::CheckForEvents()
{
    if(SDL_PollEvent(&MainMenu::event))
    {
        if(MainMenu::event.type == SDL_QUIT)
        {
            MainMenu::is_active = false;
        }

        if( MainMenu::event.type == SDL_KEYDOWN )
        {
            if( MainMenu::event.key.keysym.sym == SDLK_DOWN )
            {
                if( selected_option < 1 )
                {
                    selected_option++;
                }
                else
                {
                    selected_option = 0;
                }
            }
            else if( MainMenu::event.key.keysym.sym == SDLK_UP )
            {
                if( selected_option > 0 )
                {
                    selected_option--;
                }
                else
                {
                    selected_option = 1;
                }
            }

            if( selected_option == 0 )
            {
                MainMenu::play_option.SetColor(RED);
                MainMenu::quit_option.SetColor(WHITE);
            }

            else if( selected_option == 1 )
            {
                MainMenu::quit_option.SetColor(RED);
                MainMenu::play_option.SetColor(WHITE);
            }
        }

        //Hover play button
        if(MainMenu::play_option.IsHovered())
        {
            MainMenu::play_option.SetColor(RED);
        }
        else
        {
            MainMenu::play_option.SetColor(WHITE);
        }

        //Hover quit button
        if(MainMenu::quit_option.IsHovered())
        {
            MainMenu::quit_option.SetColor(RED);
        }
        else
        {
            MainMenu::quit_option.SetColor(WHITE);
        }

        //Click on play button
        if(MainMenu::play_option.IsClicked(MainMenu::event))
        {
            GameScene::Play();
        }

        //Click on quit button
        if(MainMenu::quit_option.IsClicked(MainMenu::event))
        {
            MainMenu::is_active = false;
        }
    }
}

void MainMenu::Render()
{
    System::Window::Clear();

    MainMenu::logo_image.Render();
    MainMenu::play_option.Render();
    MainMenu::quit_option.Render();

    System::Window::Update();
}
