#include <iostream>
#include <cstring>
#include "console.h"

using namespace std;


#ifdef _X86
#pragma message("_X86 macro activated!")
#endif

int main(int argc, char **argv){
    Console cc = Console();
    cc.accept();
    return 0;
}
