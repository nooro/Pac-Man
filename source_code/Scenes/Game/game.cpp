#include "game.h"

bool GameScene::is_active;

Map GameScene::current_map;

bool GameScene::Init()
{
    GamePanel::Init();

    if( !PacMan::Init() )
    {
        return false;
    }

    if( !GameScene::current_map.Load("Resources/Maps/test.map") )
    {
        return false;
    }

    GameScene::is_active = false;

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

        GameScene::CheckForCollisionWithWall();
        GameScene::CheckForCollisionWithPoint();

        GameScene::Render();
    }
}

void GameScene::Render()
{
    System::Window::Clear();
    GameScene::current_map.Render();
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
