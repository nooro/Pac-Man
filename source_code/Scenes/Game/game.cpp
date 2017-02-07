#include "game.h"

bool GameScene::is_active;

Map GameScene::current_map;

TTF_Font *GameScene::stats_font;

int GameScene::score;
Text GameScene::score_text;
Text GameScene::lives_text;

bool GameScene::Init()
{
    GamePanel::Init();

    if( !PacMan::Init(GamePanel::GetHeight() / 40, GamePanel::GetHeight() / 40))
    {
        return false;
    }

    GameScene::is_active = false;

    GameScene::stats_font = NULL;
    GameScene::stats_font = TTF_OpenFont(FONT_BOING, 38);
    if(GameScene::stats_font == NULL)
    {
        Error::New(Error::Type::TTF, "Can not load game statistics font");
        return false;
    }

    GameScene::score = 0;
    GameScene::score_text.Create("Score: 0", GameScene::stats_font, GREEN);
    GameScene::score_text.SetX(GamePanel::GetX() + GamePanel::GetWidth() - GameScene::score_text.GetWidth());
    GameScene::score_text.SetY(100);

    GameScene::lives_text.Create("Lives: " + to_string(PacMan::GetLives()), GameScene::stats_font, GREEN);
    GameScene::lives_text.SetX(GamePanel::GetX() + GamePanel::GetWidth() - GameScene::lives_text.GetWidth());
    GameScene::lives_text.SetY(GameScene::score_text.GetY() + GameScene::score_text.GetHeight() + 20);
    return true;
}

void GameScene::Play()
{
    GameScene::is_active = GameScene::current_map.Load("Resources/Maps/test.map");
    PacMan::ChangeWalkDirection(General::Direction::Left);

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

    GameScene::score_text.Render();
    GameScene::lives_text.Render();

    System::Window::Update();
}

const Uint8 *input = SDL_GetKeyboardState(NULL);
General::Direction previous_direction;
void GameScene::GetPlayerInput()
{
    SDL_PumpEvents();
    previous_direction = PacMan::walk_direction;

    if( PacMan::IsAlive() )
    {
        if( input[SDL_SCANCODE_LEFT] )
        {
            PacMan::ChangeWalkDirection( General::Direction::Left );
            if(previous_direction == General::Direction::Up || previous_direction == General::Direction::Down)
            {
                if(CheckForCollisionWithWall())
                {
                    PacMan::ChangeWalkDirection( previous_direction );
                }
            }
        }

        if( input[SDL_SCANCODE_RIGHT] )
        {
            PacMan::ChangeWalkDirection( General::Direction::Right );
            if(previous_direction == General::Direction::Up || previous_direction == General::Direction::Down)
            {
                if(CheckForCollisionWithWall())
                {
                    PacMan::ChangeWalkDirection( previous_direction );
                }
            }
        }

        if( input[SDL_SCANCODE_UP] )
        {
            PacMan::ChangeWalkDirection( General::Direction::Up );
            if(previous_direction == General::Direction::Left || previous_direction == General::Direction::Right)
            {
                if(CheckForCollisionWithWall())
                {
                    PacMan::ChangeWalkDirection( previous_direction );
                }
            }
        }

        if( input[SDL_SCANCODE_DOWN] )
        {
            PacMan::ChangeWalkDirection( General::Direction::Down );
            if(previous_direction == General::Direction::Left || previous_direction == General::Direction::Right)
            {
                if(CheckForCollisionWithWall())
                {
                    PacMan::ChangeWalkDirection( previous_direction );
                }
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
            if( GameScene::CheckForCollisionWithBonusPoint() )
            {
                GameScene::score += 30;
                GameScene::score_text.SetText("Score: " + to_string(GameScene::score));
                GameScene::current_map.SetWallColor(General::Colors[General::RandomNumber(0, 4)]);
            }
        }
        else
        {
            PacMan::StopWalking();
        }
    }
    else
    {
        SoundManager::Play(SoundManager::Sounds::GetCoin);
        GameScene::score += 10;
        GameScene::score_text.SetText("Score: " + to_string(GameScene::score));
    }
}
