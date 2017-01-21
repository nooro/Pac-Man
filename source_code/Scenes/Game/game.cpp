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
        GameScene::CheckForCollision();

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

void GameScene::CheckForCollision()
{
    PacMan::StartWalking();
    if( PacMan::walk_direction == PacMan::Direction::Right )
    {
        //Check for collision with the right wall of the game panel
        if( PacMan::GetX() + PacMan::GetWidth() >= GamePanel::GetX() + GamePanel::GetWidth() )
        {
            PacMan::StopWalking();
        }

        //Check for collision with wall block
//        for(int i = 0; i < WallsManager::NumberOfWalls(); i++ )
//        {
//            if( PacMan::GetX() + PacMan::GetWidth() >= WallsManager::Get(i).x )
//            {
//                if( PacMan::GetY() <= WallsManager::Get(i).y + WallsManager::Get(i).h )
//                {
//                    if( PacMan::GetY() + PacMan::GetHeight() >= WallsManager::Get(i).y )
//                    {
//                        PacMan::StopWalking();
//                    }
//                }
//            }
//        }
    }
    else if( PacMan::walk_direction == PacMan::Direction::Left )
    {
        //Check for collision with the left wall of the game panel
        if( PacMan::GetX() <= GamePanel::GetX() )
        {
            PacMan::StopWalking();
        }
//
//        //Check for collision with wall block
//        for(int i = 0; i < WallsManager::NumberOfWalls(); i++ )
//        {
//            if( PacMan::GetX() <= WallsManager::Get(i).x + WallsManager::Get(i).w )
//            {
//                if( PacMan::GetY() >= WallsManager::Get(i).y )
//                {
//                    if( PacMan::GetY() + PacMan::GetHeight() <= WallsManager::Get(i).y + WallsManager::Get(i).h )
//                    {
//                        PacMan::StopWalking();
//                    }
//                }
//            }
//        }
    }
//    else if( PacMan::walk_direction == PacMan::Direction::Up )
//    {
//        //Check for collision with the upper wall of the game panel
//        if( PacMan::GetY() <= GamePanel::GetY() )
//        {
//            PacMan::StopWalking();
//        }
//
//        //Check for collision with wall block
//        for(int i = 0; i < WallsManager::NumberOfWalls(); i++ )
//        {
//            if( PacMan::GetY() == WallsManager::Get(i).y + WallsManager::Get(i).h )
//            {
//                PacMan::StopWalking();
//            }
//        }
//    }
//    else if( PacMan::walk_direction == PacMan::Direction::Down )
//    {
//        //Check for collision with the down wall of the game panel
//        if( PacMan::GetY() + PacMan::GetHeight() >= GamePanel::GetY() + GamePanel::GetHeight() )
//        {
//            PacMan::StopWalking();
//        }
//    }
}
