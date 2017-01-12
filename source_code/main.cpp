#include "System/system.h"
#include "Scenes/Game/game.h"

int main(int argc, char ** argv)
{
    if( !System::Init() ) { return -1; }
    if( !GameScene::Init() ) { return -1; }

    GameScene::Play();

    return 0;
}
