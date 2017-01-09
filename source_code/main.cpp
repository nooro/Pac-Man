#include "System/system.h"
#include "Entities/pac_man.h"
#include "Scenes/game.h"

int main(int argc, char ** argv)
{
    if( !System::Init() ) { return -1; }
    if( !PacMan::Init() ) { return -1; }
    if( !GameScene::Init() ) { return -1; }

    GameScene::Play();

    return 0;
}
