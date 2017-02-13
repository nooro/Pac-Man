#include "main_menu.h"

bool MainMenu::is_active;
Image MainMenu::logo_image;

TTF_Font *MainMenu::options_font;
#define OPTIONS 2
#define PLAY 0
#define QUIT 1
Link MainMenu::options[OPTIONS];
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

    if ( !MainMenu::options[PLAY].Create("Play", MainMenu::options_font, WHITE) )
    {
        Error::New(Error::Type::TTF, "Could not create the play option text from the main menu");
        return false;
    }
    MainMenu::options[PLAY].SetX( (System::Window::GetWidth() / 2) - (MainMenu::options[PLAY].GetWidth() / 2) );
    MainMenu::options[PLAY].SetY( MainMenu::logo_image.GetY() + MainMenu::logo_image.GetHeight() + ( System::Window::GetHeight() / 5 ) );

    if ( !MainMenu::options[QUIT].Create("Quit", MainMenu::options_font, WHITE) )
    {
        Error::New(Error::Type::TTF, "Could not create the quit option text from the main menu");
        return false;
    }
    MainMenu::options[QUIT].SetX( (System::Window::GetWidth() / 2) - (MainMenu::options[QUIT].GetWidth() / 2) );
    MainMenu::options[QUIT].SetY( MainMenu::options[PLAY].GetY() + MainMenu::options[PLAY].GetHeight() + 20 );

    MainMenu::selected_option = PLAY;

    MainMenu::is_active = false;

    return true;
}

void MainMenu::Free()
{
    delete(&MainMenu::logo_image);
    delete(&MainMenu::options);
    TTF_CloseFont(MainMenu::options_font);
}

void MainMenu::Play()
{
    MainMenu::is_active = true;
    MainMenu::options[MainMenu::selected_option].SetColor(RED);
    MainMenu::Render();

    while( MainMenu::is_active )
    {
        if( MainMenu::CheckForEvents() )
        {
            for(int i = 0; i < OPTIONS; i++)
            {
                if( MainMenu::selected_option == i )
                {
                    MainMenu::options[i].SetColor(RED);
                }
                else
                {
                    MainMenu::options[i].SetColor(WHITE);
                }
            }

            MainMenu::Render();
        }
    }
}

SDL_Event MainMenu::event;
bool MainMenu::CheckForEvents()
{
    if(SDL_PollEvent(&MainMenu::event))
    {
        if( MainMenu::event.type == SDL_KEYDOWN )
        {
            if( MainMenu::event.key.keysym.sym == SDLK_DOWN )
            {
                if( MainMenu::selected_option < OPTIONS - 1)
                {
                    MainMenu::selected_option++;
                }
                else
                {
                    MainMenu::selected_option = 0;
                }
                return true;
            }
            else if( MainMenu::event.key.keysym.sym == SDLK_UP )
            {
                if( MainMenu::selected_option > 0 )
                {
                    MainMenu::selected_option--;
                }
                else
                {
                    MainMenu::selected_option = OPTIONS - 1;
                }
                return true;
            }
            else if( MainMenu::event.key.keysym.sym == SDLK_RETURN || MainMenu::event.key.keysym.sym == SDLK_RETURN2 )
            {
                if( MainMenu::selected_option == PLAY )
                {
                    GameScene::Play();
                }
                else if( MainMenu::selected_option == QUIT )
                {
                    MainMenu::is_active = false;
                }
                return true;
            }
        }

        if( MainMenu::options[PLAY].IsClicked(MainMenu::event) )
        {
            GameScene::Play();
            return true;
        }
        else if( MainMenu::options[QUIT].IsClicked(MainMenu::event) )
        {
            MainMenu::is_active = false;
            return true;
        }

        if( MainMenu::options[PLAY].IsHovered() )
        {
            MainMenu::selected_option = PLAY;
            return true;
        }
        else if( MainMenu::options[QUIT].IsHovered() )
        {
            MainMenu::selected_option = QUIT;
            return true;
        }

        if(MainMenu::event.type == SDL_QUIT)
        {
            MainMenu::is_active = false;
            return true;
        }
    }
    return false;
}

void MainMenu::Render()
{
    System::Window::Clear();

    MainMenu::logo_image.Render();

    for(int i = 0; i < OPTIONS; i++)
    {
        MainMenu::options[i].Render();
    }

    System::Window::Update();
}
