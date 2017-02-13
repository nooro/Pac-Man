#include "System/system.h"
#include "Scenes/MainMenu/main_menu.h"
#include "Scenes/Game/game.h"
#include "Scenes/PauseMenu/pause_menu.h"

bool InitEverything()
{
    return  System::Init() &&
            SoundManager::Init() &&
            MainMenu::Init() &&
            PauseMenu::Init() &&
            GameScene::Init();
}

void FreeUsedMemory()
{
    MainMenu::Free();
    PauseMenu::Free();
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
