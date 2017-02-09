#include "bonus_points_manager.h"

SDL_Texture *BonusPointsManager::texture = NULL;
vector<SDL_Rect> BonusPointsManager::points;
SDL_Color BonusPointsManager::color;

void BonusPointsManager::Add(SDL_Rect rect)
{
    BonusPointsManager::points.push_back(rect);
}

void BonusPointsManager::Delete(int index)
{
    BonusPointsManager::points.erase(BonusPointsManager::points.begin() + index);
}

void BonusPointsManager::SetColor(SDL_Color color)
{
    BonusPointsManager::texture = CreateTexture(POINT_IMAGE);
    SDL_SetTextureColorMod(BonusPointsManager::texture, color.r, color.g, color.b);
}

void BonusPointsManager::Clear()
{
    BonusPointsManager::points.clear();
}

void BonusPointsManager::Free()
{
    SDL_DestroyTexture(BonusPointsManager::texture);
    BonusPointsManager::Clear();
    delete(&BonusPointsManager::points);
    delete(&BonusPointsManager::color);
}

void BonusPointsManager::Render()
{
    for(unsigned int i = 0; i < BonusPointsManager::points.size(); i++)
    {
        SDL_RenderCopy(System::Renderer, BonusPointsManager::texture, NULL, &BonusPointsManager::points[i]);
    }
}

SDL_Rect BonusPointsManager::Get(int index) { return BonusPointsManager::points[index]; }

int BonusPointsManager::NumberOfPoints() { return BonusPointsManager::points.size(); }
