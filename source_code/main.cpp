#include "System/system.h"
#include "Scenes/MainMenu/main_menu.h"
#include "Scenes/Game/game.h"

bool InitEverything()
{
    return  System::Init() &&
            SoundManager::Init() &&
            MainMenu::Init() &&
            GameScene::Init();
}

void FreeUsedMemory()
{
    MainMenu::Free();
    GameScene::Free();
    SoundManager::Free();
    System::Free();
}

int main(int argc, char ** argv)
{
    if( !InitEverything() ) { return - 1; }

    MainMenu::Play();

    FreeUsedMemory();
    return 0;
}
