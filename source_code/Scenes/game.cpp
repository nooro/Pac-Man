#include "game.h"

bool GameScene::is_active;
SDL_Rect GameScene::game_panel;

bool GameScene::Init()
{
    if( !PacMan::Init() )
    {
        return false;
    }

    GameScene::is_active = false;

    //Initialize the resolution for the game panel (5:4)
    GameScene::game_panel.h = System::Window::GetHeight();
    GameScene::game_panel.w = System::Window::GetHeight() + ( System::Window::GetHeight() / 4 );
    //Center the game panel
    GameScene::game_panel.x = ( System::Window::GetWidth() / 2 ) - ( GameScene::game_panel.w / 2 ) ;
    GameScene::game_panel.y = 0;

    return true;
}

void GameScene::Play()
{
    GameScene::is_active = true;
    PacMan::ChangeWalkDirection(PacMan::Direction::Left);

    while( GameScene::is_active )
    {
        GameScene::GetPlayerInput();
        PacMan::Update();

        GameScene::Render();
    }
}

void GameScene::Render()
{
    System::Window::Clear();
    PacMan::Render();
    System::Window::Update();
}

const Uint8 *input = SDL_GetKeyboardState(NULL);
void GameScene::GetPlayerInput()
{
    SDL_PumpEvents();

    if( input[SDL_SCANCODE_LEFT] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Left );
    }

    if( input[SDL_SCANCODE_RIGHT] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Right );
    }

    if( input[SDL_SCANCODE_UP] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Up );
    }

    if( input[SDL_SCANCODE_DOWN] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Down );
    }
}
