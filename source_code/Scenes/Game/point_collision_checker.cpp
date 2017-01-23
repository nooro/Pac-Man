#include "game.h"

int collider_point_index;

bool is_collide_on_right_walking()
{
    for(int i = 0; i < PointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetX() + PacMan::GetWidth() >= PointsManager::Get(i).x )
        {
            if( PacMan::GetX() + PacMan::GetWidth() <= PointsManager::Get(i).x + PointsManager::Get(i).w )
            {
                if( PointsManager::Get(i).y >= PacMan::GetY() )
                {
                    if( PointsManager::Get(i).y + PointsManager::Get(i).h <= PacMan::GetY() + PacMan::GetHeight() )
                    {
                        collider_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool is_collide_on_left_walking()
{
    for(int i = 0; i < PointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetX() <= PointsManager::Get(i).x + PointsManager::Get(i).w )
        {
            if( PacMan::GetX() >= PointsManager::Get(i).x )
            {
                if( PointsManager::Get(i).y >= PacMan::GetY() )
                {
                    if( PointsManager::Get(i).y + PointsManager::Get(i).h <= PacMan::GetY() + PacMan::GetHeight() )
                    {
                        collider_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_collide_on_up_walking()
{
    for(int i = 0; i < PointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetY() <= PointsManager::Get(i).y + PointsManager::Get(i).h )
        {
            if( PacMan::GetY() >= PointsManager::Get(i).y )
            {
                if( PointsManager::Get(i).x >= PacMan::GetX() )
                {
                    if( PointsManager::Get(i).x + PointsManager::Get(i).w  <= PacMan::GetX() + PacMan::GetWidth() )
                    {
                        collider_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool is_collide_on_down_walking()
{
    for(int i = 0; i < PointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetY() + PacMan::GetHeight() >= PointsManager::Get(i).y )
        {
            if( PacMan::GetY() <= PointsManager::Get(i).y )
            {
                if( PointsManager::Get(i).x >= PacMan::GetX() )
                {
                    if( PointsManager::Get(i).x + PointsManager::Get(i).w  <= PacMan::GetX() + PacMan::GetWidth() )
                    {
                        collider_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void GameScene::CheckForCollisionWithPoint()
{
    if( PacMan::walk_direction == PacMan::Direction::Right )
    {
        if( is_collide_on_right_walking() )
        {
            PointsManager::Delete(collider_point_index);
        }
    }
    else if( PacMan::walk_direction == PacMan::Direction::Left )
    {
        if( is_collide_on_left_walking() )
        {
            PointsManager::Delete(collider_point_index);
        }
    }
    else if( PacMan::walk_direction == PacMan::Direction::Up )
    {
        if( is_collide_on_up_walking() )
        {
            PointsManager::Delete(collider_point_index);
        }
    }
    else if( PacMan::walk_direction == PacMan::Direction::Down )
    {
        if( is_collide_on_down_walking() )
        {
            PointsManager::Delete(collider_point_index);
        }
    }
}
