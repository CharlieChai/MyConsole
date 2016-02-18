#include <iostream>

#include "console.h"
#include "sales_data.h"
#include "cprocess.h"

using namespace std;


#ifdef _X86
#pragma message("_X86 macro activated!")
#endif

void f(int a){
    cout <<  a << endl;
}

int main(int argc, char **argv){
    //Console initialization
    Console init = Console();
    init.accept();
}

