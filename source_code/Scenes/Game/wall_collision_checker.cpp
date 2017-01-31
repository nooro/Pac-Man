#include "game.h"

int collider_wall_index;

bool is_collide_when_right_walking()
{
    for(int i = 0; i < WallsManager::NumberOfWalls(); i++ )
    {
        if( PacMan::GetX() + PacMan::GetWidth() >= WallsManager::Get(i).x - ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2))
        {
            if( PacMan::GetX() + PacMan::GetWidth() <= WallsManager::Get(i).x + WallsManager::Get(i).w )
            {
                //In this case Pac-Man is in the middle of the block
                if( PacMan::GetY() >= WallsManager::Get(i).y )
                {
                    if( PacMan::GetY() + PacMan::GetHeight() <= WallsManager::Get(i).y + WallsManager::Get(i).h )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only bottom part of Pac-Man is touching the wall
                if( PacMan::GetY() <= WallsManager::Get(i).y )
                {
                    if( PacMan::GetY() + PacMan::GetHeight() >= WallsManager::Get(i).y )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only top part of Pac-Man is touching the wall
                if( PacMan::GetY() + PacMan::GetHeight() >= WallsManager::Get(i).y + WallsManager::Get(i).h )
                {
                    if( PacMan::GetY() <= WallsManager::Get(i).y + WallsManager::Get(i).h )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_collide_when_left_walking()
{
    for(int i = 0; i < WallsManager::NumberOfWalls(); i++ )
    {
        if( PacMan::GetX() <= WallsManager::Get(i).x + WallsManager::Get(i).w + ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2))
        {
            if( PacMan::GetX() >= WallsManager::Get(i).x )
            {
                //In this case Pac-Man is in the middle of the block
                if( PacMan::GetY() >= WallsManager::Get(i).y )
                {
                    if( PacMan::GetY() + PacMan::GetHeight() <= WallsManager::Get(i).y + WallsManager::Get(i).h )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only bottom part of Pac-Man is touching the wall
                if( PacMan::GetY() <= WallsManager::Get(i).y )
                {
                    if( PacMan::GetY() + PacMan::GetHeight() >= WallsManager::Get(i).y )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only top part of Pac-Man is touching the wall
                if( PacMan::GetY() + PacMan::GetHeight() >= WallsManager::Get(i).y + WallsManager::Get(i).h )
                {
                    if( PacMan::GetY() <= WallsManager::Get(i).y + WallsManager::Get(i).h )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_collide_when_up_walking()
{
    for(int i = 0; i < WallsManager::NumberOfWalls(); i++ )
    {
        if( PacMan::GetY() <= WallsManager::Get(i).y + WallsManager::Get(i).h + ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2) )
        {
            if( PacMan::GetY() >= WallsManager::Get(i).y )
            {
                //In this case Pac-Man is in the middle of the block
                if( PacMan::GetX() >= WallsManager::Get(i).x )
                {
                    if( PacMan::GetX() + PacMan::GetWidth() <= WallsManager::Get(i).x + WallsManager::Get(i).w )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only right part of Pac-Man is touching the wall
                if( PacMan::GetX() <= WallsManager::Get(i).x )
                {
                    if( PacMan::GetX() + PacMan::GetWidth() >= WallsManager::Get(i).x )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only left part of Pac-Man is touching the wall
                if( PacMan::GetX() <= WallsManager::Get(i).x + WallsManager::Get(i).w )
                {
                    if( PacMan::GetX() + PacMan::GetWidth() >= WallsManager::Get(i).x + WallsManager::Get(i).w )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_collide_when_down_walking()
{
    for(int i = 0; i < WallsManager::NumberOfWalls(); i++ )
    {
        if( PacMan::GetY() + PacMan::GetHeight() >= WallsManager::Get(i).y - ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2) )
        {
            if( PacMan::GetY() + PacMan::GetHeight() <= WallsManager::Get(i).y + WallsManager::Get(i).h )
            {
                //In this case Pac-Man is in the middle of the block
                if( PacMan::GetX() >= WallsManager::Get(i).x )
                {
                    if( PacMan::GetX() + PacMan::GetWidth() <= WallsManager::Get(i).x + WallsManager::Get(i).w )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only right part of Pac-Man is touching the wall
                if( PacMan::GetX() <= WallsManager::Get(i).x )
                {
                    if( PacMan::GetX() + PacMan::GetWidth() >= WallsManager::Get(i).x )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
                //In this case only left part of Pac-Man is touching the wall
                if( PacMan::GetX() <= WallsManager::Get(i).x + WallsManager::Get(i).w )
                {
                    if( PacMan::GetX() + PacMan::GetWidth() >= WallsManager::Get(i).x + WallsManager::Get(i).w )
                    {
                        collider_wall_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool GameScene::CheckForCollisionWithWall()
{
    PacMan::StartWalking();

    if( PacMan::walk_direction == PacMan::Direction::Right )
    {
        if( is_collide_when_right_walking() )
        {
            PacMan::SetX(WallsManager::Get(collider_wall_index).x - PacMan::GetWidth() - ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2));
            return true;
        }
    }
    else if( PacMan::walk_direction == PacMan::Direction::Left )
    {
        if( is_collide_when_left_walking() )
        {
            PacMan::SetX(WallsManager::Get(collider_wall_index).x + WallsManager::Get(collider_wall_index).w + ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2));
            return true;
        }
    }
    else if( PacMan::walk_direction == PacMan::Direction::Up )
    {
        if( is_collide_when_up_walking() )
        {
            PacMan::SetY( WallsManager::Get(collider_wall_index).y + WallsManager::Get(collider_wall_index).h + ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2));
            return true;
        }
    }
    else if( PacMan::walk_direction == PacMan::Direction::Down )
    {
        if( is_collide_when_down_walking() )
        {
            PacMan::SetY( WallsManager::Get(collider_wall_index).y - PacMan::GetHeight() - ((GamePanel::GetHeight() / 30 - PacMan::GetWidth()) / 2));
            return true;
        }
    }
    return false;
}
