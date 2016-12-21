#include <iostream>
#include <string>
#include "console.h"
#include "quicksort.h"

using namespace std;
using IntroductionToAlgorithm::SortAlgorithm::partition;
using IntroductionToAlgorithm::SortAlgorithm::quick_sort;

#ifdef _X86
#pragma message("_X86 macro activated!")
#endif

int main(int argc, char **argv){
    Console cc = Console().accept();
    return 0;
}
