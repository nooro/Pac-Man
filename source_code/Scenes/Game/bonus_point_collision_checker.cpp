#include "game.h"

int collided_point_index;

bool collide_on_right_walking()
{
    for(int i = 0; i < BonusPointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetX() + PacMan::GetWidth() >= BonusPointsManager::Get(i).x )
        {
            if( PacMan::GetX() + PacMan::GetWidth() <= BonusPointsManager::Get(i).x + BonusPointsManager::Get(i).w )
            {
                if( BonusPointsManager::Get(i).y >= PacMan::GetY() )
                {
                    if( BonusPointsManager::Get(i).y + BonusPointsManager::Get(i).h <= PacMan::GetY() + PacMan::GetHeight() )
                    {
                        collided_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool collide_on_left_walking()
{
    for(int i = 0; i < BonusPointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetX() <= BonusPointsManager::Get(i).x + BonusPointsManager::Get(i).w )
        {
            if( PacMan::GetX() >= BonusPointsManager::Get(i).x )
            {
                if( BonusPointsManager::Get(i).y >= PacMan::GetY() )
                {
                    if( BonusPointsManager::Get(i).y + BonusPointsManager::Get(i).h <= PacMan::GetY() + PacMan::GetHeight() )
                    {
                        collided_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool collide_on_up_walking()
{
    for(int i = 0; i < BonusPointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetY() <= BonusPointsManager::Get(i).y + BonusPointsManager::Get(i).h )
        {
            if( PacMan::GetY() >= BonusPointsManager::Get(i).y )
            {
                if( BonusPointsManager::Get(i).x >= PacMan::GetX() )
                {
                    if( BonusPointsManager::Get(i).x + BonusPointsManager::Get(i).w  <= PacMan::GetX() + PacMan::GetWidth() )
                    {
                        collided_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool collide_on_down_walking()
{
    for(int i = 0; i < BonusPointsManager::NumberOfPoints(); i++ )
    {
        if( PacMan::GetY() + PacMan::GetHeight() >= BonusPointsManager::Get(i).y )
        {
            if( PacMan::GetY() <= BonusPointsManager::Get(i).y )
            {
                if( BonusPointsManager::Get(i).x >= PacMan::GetX() )
                {
                    if( BonusPointsManager::Get(i).x + BonusPointsManager::Get(i).w  <= PacMan::GetX() + PacMan::GetWidth() )
                    {
                        collided_point_index = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool GameScene::CheckForCollisionWithBonusPoint()
{
    if( PacMan::walk_direction == General::Direction::Right )
    {
        if( collide_on_right_walking() )
        {
            BonusPointsManager::Delete(collided_point_index);
            return true;
        }
    }
    else if( PacMan::walk_direction == General::Direction::Left )
    {
        if( collide_on_left_walking() )
        {
            BonusPointsManager::Delete(collided_point_index);
            return true;
        }
    }
    else if( PacMan::walk_direction == General::Direction::Up )
    {
        if( collide_on_up_walking() )
        {
            BonusPointsManager::Delete(collided_point_index);
            return true;
        }
    }
    else if( PacMan::walk_direction == General::Direction::Down )
    {
        if( collide_on_down_walking() )
        {
            BonusPointsManager::Delete(collided_point_index);
            return true;
        }
    }

    return false;
}
