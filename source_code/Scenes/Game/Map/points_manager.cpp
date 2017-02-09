#include "points_manager.h"

SDL_Texture *PointsManager::texture = NULL;
vector<SDL_Rect> PointsManager::points;
SDL_Color PointsManager::color;


void PointsManager::Add(SDL_Rect rect)
{
    PointsManager::points.push_back(rect);
}

void PointsManager::Delete(int index)
{
    PointsManager::points.erase(PointsManager::points.begin() + index);
}

void PointsManager::SetColor(SDL_Color color)
{
    PointsManager::texture = CreateTexture(POINT_IMAGE);
    SDL_SetTextureColorMod(PointsManager::texture, color.r, color.g, color.b);
}

void PointsManager::Clear()
{
    PointsManager::points.clear();
}

void PointsManager::Free()
{
    SDL_DestroyTexture(PointsManager::texture);
    PointsManager::Clear();
    delete(&PointsManager::points);
    delete(&PointsManager::color);
}

void PointsManager::Render()
{
    for(unsigned int i = 0; i < PointsManager::points.size(); i++)
    {
        SDL_RenderCopy(System::Renderer, PointsManager::texture, NULL, &PointsManager::points[i]);
    }
}

SDL_Rect PointsManager::Get(int index) { return PointsManager::points[index]; }

int PointsManager::NumberOfPoints() { return PointsManager::points.size(); }
