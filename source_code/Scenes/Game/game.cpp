#include "game.h"

bool GameScene::is_active;

Map GameScene::current_map;
Ghost ghost;
bool GameScene::Init()
{
    GamePanel::Init();

    if( !PacMan::Init(GamePanel::GetHeight() / 40, GamePanel::GetHeight() / 40))
    {
        return false;
    }

    if( !ghost.Init(GamePanel::GetHeight() / 40, GamePanel::GetHeight() / 40))
    {
        return false;
    }

    GameScene::is_active = false;

    return true;
}

void GameScene::Play()
{
    GameScene::is_active = GameScene::current_map.Load("Resources/Maps/test.map");
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
PacMan::Direction previous_direction;
void GameScene::GetPlayerInput()
{
    SDL_PumpEvents();
    previous_direction = PacMan::walk_direction;

    if( input[SDL_SCANCODE_LEFT] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Left );
        if(previous_direction == PacMan::Direction::Up || previous_direction == PacMan::Direction::Down)
        {
            if(CheckForCollisionWithWall())
            {
                PacMan::ChangeWalkDirection( previous_direction );
            }
        }
    }

    if( input[SDL_SCANCODE_RIGHT] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Right );
        if(previous_direction == PacMan::Direction::Up || previous_direction == PacMan::Direction::Down)
        {
            if(CheckForCollisionWithWall())
            {
                PacMan::ChangeWalkDirection( previous_direction );
            }
        }
    }

    if( input[SDL_SCANCODE_UP] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Up );
        if(previous_direction == PacMan::Direction::Left || previous_direction == PacMan::Direction::Right)
        {
            if(CheckForCollisionWithWall())
            {
                PacMan::ChangeWalkDirection( previous_direction );
            }
        }
    }

    if( input[SDL_SCANCODE_DOWN] )
    {
        PacMan::ChangeWalkDirection( PacMan::Direction::Down );
        if(previous_direction == PacMan::Direction::Left || previous_direction == PacMan::Direction::Right)
        {
            if(CheckForCollisionWithWall())
            {
                PacMan::ChangeWalkDirection( previous_direction );
            }
        }
    }
}

void GameScene::CheckForCollision()
{
    if( !GameScene::CheckForCollisionWithPoint() )
    {
        if( !GameScene::CheckForCollisionWithWall() )
        {
            GameScene::CheckForCollisionWithBonusPoint();
        }
        else
        {
            PacMan::StopWalking();
        }
    }
}
