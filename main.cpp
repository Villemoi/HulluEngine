#include "classes.h"
#include "start.cpp"
#include "loop.cpp"
#include "shutdown.cpp"

int main(int argc, char* argv[]) {
    skene sk = start();
    loop(sk, argc, argv);
    shutdown();
    return 0;
}

