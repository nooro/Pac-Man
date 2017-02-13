#include "pause_menu.h"


bool PauseMenu::is_active;

TTF_Font *PauseMenu::options_font;
#define OPTIONS 2
#define RESUME 0
#define MAIN_MENU 1
Link PauseMenu::options[OPTIONS];
int PauseMenu::selected_option;

bool PauseMenu::Init()
{
    PauseMenu::options_font = NULL;
    PauseMenu::options_font = TTF_OpenFont(FONT_BOING, 60);
    if(PauseMenu::options_font == NULL)
    {
        Error::New(Error::Type::TTF, "Can not load main menu options font");
        return false;
    }

    if ( !PauseMenu::options[RESUME].Create("Resume", PauseMenu::options_font, WHITE) )
    {
        Error::New(Error::Type::TTF, "Could not create the resume option text from the main menu");
        return false;
    }
    PauseMenu::options[RESUME].SetX( (System::Window::GetWidth() / 2) - (PauseMenu::options[RESUME].GetWidth() / 2) );

    if ( !PauseMenu::options[MAIN_MENU].Create("Main menu", PauseMenu::options_font, WHITE) )
    {
        Error::New(Error::Type::TTF, "Could not create the main menu option text from the main menu");
        return false;
    }
    PauseMenu::options[MAIN_MENU].SetX( (System::Window::GetWidth() / 2) - (PauseMenu::options[MAIN_MENU].GetWidth() / 2) );
    PauseMenu::options[MAIN_MENU].SetY( PauseMenu::options[RESUME].GetY() + PauseMenu::options[RESUME].GetHeight() + 20 );

    PauseMenu::selected_option = RESUME;

    PauseMenu::is_active = false;

    return true;
}

void PauseMenu::Free()
{
    delete(&PauseMenu::options);
    TTF_CloseFont(PauseMenu::options_font);
}

void PauseMenu::Play()
{
    PauseMenu::is_active = true;
    PauseMenu::options[PauseMenu::selected_option].SetColor(RED);
    PauseMenu::Render();

    while( PauseMenu::is_active )
    {
        if( PauseMenu::CheckForEvents() )
        {
            for(int i = 0; i < OPTIONS; i++)
            {
                if( PauseMenu::selected_option == i )
                {
                    PauseMenu::options[i].SetColor(RED);
                }
                else
                {
                    PauseMenu::options[i].SetColor(WHITE);
                }
            }

            PauseMenu::Render();
        }
    }
}

SDL_Event PauseMenu::event;
bool PauseMenu::CheckForEvents()
{
    if(SDL_PollEvent(&PauseMenu::event))
    {
        if( PauseMenu::event.type == SDL_KEYDOWN )
        {
            if( PauseMenu::event.key.keysym.sym == SDLK_DOWN )
            {
                if( PauseMenu::selected_option < OPTIONS - 1)
                {
                    PauseMenu::selected_option++;
                }
                else
                {
                    PauseMenu::selected_option = 0;
                }
                SoundManager::Play(SoundManager::Sounds::Click);
                return true;
            }
            else if( PauseMenu::event.key.keysym.sym == SDLK_UP )
            {
                if( PauseMenu::selected_option > 0 )
                {
                    PauseMenu::selected_option--;
                }
                else
                {
                    PauseMenu::selected_option = OPTIONS - 1;
                }
                SoundManager::Play(SoundManager::Sounds::Click);
                return true;
            }
            else if( PauseMenu::event.key.keysym.sym == SDLK_RETURN || PauseMenu::event.key.keysym.sym == SDLK_RETURN2 )
            {
                if( PauseMenu::selected_option == RESUME )
                {
                    PauseMenu::is_active = false;
                }
                else if( PauseMenu::selected_option == MAIN_MENU )
                {
                    PauseMenu::is_active = false;
                    GameScene::Close();
                    MainMenu::Play();
                }
                return true;
            }
        }

        if( PauseMenu::options[RESUME].IsClicked(PauseMenu::event) )
        {
            PauseMenu::is_active = false;
            return true;
        }
        else if( PauseMenu::options[MAIN_MENU].IsClicked(PauseMenu::event) )
        {
            PauseMenu::is_active = false;
            GameScene::Close();
            MainMenu::Play();
            return true;
        }

        if( PauseMenu::options[RESUME].IsHovered() )
        {
            PauseMenu::selected_option = RESUME;
            SoundManager::Play(SoundManager::Sounds::Click);
            return true;
        }
        else if( PauseMenu::options[MAIN_MENU].IsHovered() )
        {
            PauseMenu::selected_option = MAIN_MENU;
            SoundManager::Play(SoundManager::Sounds::Click);
            return true;
        }

        if(PauseMenu::event.type == SDL_QUIT)
        {
            PauseMenu::is_active = false;
            return true;
        }
    }
    return false;
}

void PauseMenu::Render()
{
    if( PauseMenu::is_active )
    {
        System::Window::Clear();

        for(int i = 0; i < OPTIONS; i++)
        {
            PauseMenu::options[i].Render();
        }

        System::Window::Update();
    }
}

