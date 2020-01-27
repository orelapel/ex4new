#include "boot.h"
using namespace boot;

int main(int argc,char* argv[]) {
    Main m;
    if (argc < 2){
        m.main(5400);
    } else{
        m.main(atoi(argv[1]));
    }
    return 0;
}

