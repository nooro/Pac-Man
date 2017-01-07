#include "System/system.h"
#include "Entities/pac_man.h"

int main(int argc, char ** argv)
{
    if( !System::Init() ) { return -1; }
    if( !PacMan::Init() ) { return -2; }

    return 0;
}
