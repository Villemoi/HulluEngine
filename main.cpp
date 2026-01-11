#include "classes.h"
#include "start.cpp"
#include "loop.cpp"
#include "shutdown.cpp"

int main() {
    skene sk = start();
    loop(sk);
    shutdown();
    return 0;
}

