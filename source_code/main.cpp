#include "System/system.h"
#include "Scenes/MainMenu/main_menu.h"
#include "Scenes/Game/game.h"

int main(int argc, char ** argv)
{
    if( !System::Init() ) { return -1; }

    if( !SoundManager::Init() ) { return -1; }

    if( !MainMenu::Init() ) { return -1; }
    if( !GameScene::Init() ) { return -1; }

    MainMenu::Play();

    return 0;
}
