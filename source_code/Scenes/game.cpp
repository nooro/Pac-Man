#include "game.h"

bool GameScene::is_active;

bool GameScene::Init()
{
    GameScene::is_active = false;

    return true;
}

void GameScene::Play()
{
    GameScene::is_active = true;
    while( GameScene::is_active )
    {
        System::Window::Clear();
        PacMan::Update();
        PacMan::Render();
        System::Window::Update();
    }
}
