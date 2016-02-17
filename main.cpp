#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cctype>
#include <assert.h>
#include <map>
#include <functional>

#include "sales_data.h"
#include "screen.h"
#include "console.h"

using namespace std;


#ifdef _X86
#pragma message("_X86 macro activated!")
#endif

void f(){
    cout <<  1 << endl;
}

int main(int argc, char **argv){
    //Console initialization
    Console init = Console();
    init.accept();
}

