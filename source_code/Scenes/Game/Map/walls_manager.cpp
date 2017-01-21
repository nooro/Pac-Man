#include "walls_manager.h"

SDL_Texture *WallsManager::texture = NULL;
vector<SDL_Rect> WallsManager::walls;
SDL_Color WallsManager::color;


void WallsManager::Add(SDL_Rect rect)
{
    WallsManager::walls.push_back(rect);
}

void WallsManager::SetColor(SDL_Color color)
{
    WallsManager::texture = CreateTexture(WALL_IMAGE);
    SDL_SetTextureColorMod(WallsManager::texture, color.r, color.g, color.b);
}

void WallsManager::Clear()
{
    WallsManager::walls.clear();
}

void WallsManager::Render()
{
    for(unsigned int i = 0; i < WallsManager::walls.size(); i++)
    {
        SDL_RenderCopy(System::Renderer, WallsManager::texture, NULL, &WallsManager::walls[i]);
    }
}


SDL_Rect WallsManager::Get(int index) { return WallsManager::walls[index]; }

int WallsManager::NumberOfWalls() { return WallsManager::walls.size(); }
