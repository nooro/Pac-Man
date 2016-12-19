#include "System/system.h"

int main(int argc, char ** argv)
{
    if( System::Init() == false ) { return -1; }


    return 0;
}
