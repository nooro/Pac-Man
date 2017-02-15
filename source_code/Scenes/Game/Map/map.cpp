#include "map.h"

bool Map::Load(string file_path)
{
    WallsManager::Clear();

    PointsManager::Clear();
    PointsManager::SetColor( WHITE );

    BonusPointsManager::Clear();
    BonusPointsManager::SetColor( PINK );

    ifstream file;
    file.open(file_path);

    if( file.fail() )
    {
        string error_message = "Can not load " + file_path;
        Error::New( Error::Type::Custom, error_message );
        return false;
    }

    char current_element;
    SDL_Rect current_wall_rect;
    current_wall_rect.h = GamePanel::GetHeight() / 31;
    current_wall_rect.w = current_wall_rect.h;
    current_wall_rect.x = 0;
    current_wall_rect.y = 0;

    SDL_Rect current_point_rect;
    current_point_rect.h = current_wall_rect.h / 3;
    current_point_rect.w = current_point_rect.h;
    current_point_rect.x = 0;
    current_point_rect.y = 0;

    SDL_Rect current_bonus_point_rect;
    current_bonus_point_rect.h = current_wall_rect.h / 1.5;
    current_bonus_point_rect.w = current_bonus_point_rect.h;
    current_bonus_point_rect.x = 0;
    current_bonus_point_rect.y = 0;

    SDL_Rect first_portal_entrance;
    first_portal_entrance.h = current_wall_rect.h;
    first_portal_entrance.w = current_wall_rect.w;
    first_portal_entrance.x = 0;
    first_portal_entrance.y = 0;

    SDL_Rect second_portal_entrance;
    second_portal_entrance.h = current_wall_rect.h;
    second_portal_entrance.w = current_wall_rect.w;
    second_portal_entrance.x = 0;
    second_portal_entrance.y = 0;
    int portals = 0;

    int line = 0;
    int element = 0;

    //Read the file char by char
    while ( file >> noskipws >> current_element)
    {
        if(current_element == WALL)
        {
            current_wall_rect.x = GamePanel::GetX() + element * current_wall_rect.w;
            current_wall_rect.y = line * current_wall_rect.h;

            WallsManager::Add(current_wall_rect);

            element++;
        }
        else if(current_element == POINT)
        {
            current_point_rect.x = ( GamePanel::GetX() + element * current_wall_rect.w ) + current_point_rect.w;
            current_point_rect.y = ( line * current_wall_rect.h ) + current_point_rect.h;
            PointsManager::Add(current_point_rect);
            element++;
        }
        else if(current_element == BONUS_POINT)
        {
            current_bonus_point_rect.x = ( GamePanel::GetX() + element * current_wall_rect.w ) + ( current_point_rect.w  / 2);
            current_bonus_point_rect.y = ( line * current_wall_rect.h ) + + ( current_point_rect.w / 2);
            BonusPointsManager::Add(current_bonus_point_rect);
            element++;
        }
        else if(current_element == PORTAL)
        {
            if(portals == 0)
            {
                first_portal_entrance.x = GamePanel::GetX() + element * current_wall_rect.w;
                first_portal_entrance.y = line * current_wall_rect.h;
                portals++;

                element++;
            }
            else if( portals == 1)
            {
                second_portal_entrance.x = GamePanel::GetX() + element * current_wall_rect.w;
                second_portal_entrance.y = line * current_wall_rect.h;
                portals++;

                element++;
            }
        }
        else if(current_element == EMPTY_SPACE)
        {
            element++;
        }
        else if(current_element == NEW_LINE)
        {
            line++;
            element = 0;
        }
        else if(current_element == PACMAN)
        {
            PacMan::SetX(GamePanel::GetX() + element * current_wall_rect.w);
            PacMan::SetY( (line * current_wall_rect.h) + ((current_wall_rect.h - PacMan::GetHeight()) / 2) );
            element++;
        }

    }

    if( portals == 2 )
    {
        if( !Portal::Add(first_portal_entrance, second_portal_entrance) )
        {
            Error::New(Error::Type::Custom, "Could not create the portal");
            return false;
        }
    }

    this->SetWallColor( General::Colors[General::RandomNumber(0, 4)] );

    file.close();

    return true;
}

void Map::Free()
{
    WallsManager::Free();
    PointsManager::Free();
    BonusPointsManager::Free();
    Portal::Free();
}

void Map::Render()
{
    WallsManager::Render();
    PointsManager::Render();
    BonusPointsManager::Render();
    Portal::Render();
}

void Map::SetWallColor(SDL_Color color)
{
    WallsManager::SetColor(color);
    Portal::SetColor(color);
}
