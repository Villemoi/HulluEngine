#include "./Classes/scene.h"
#include "./Code/start.cpp"
#include "./Code/loop.cpp"
#include "./Code/shutdown.cpp"

int main(int argc, char* argv[]) {
    Scene sk = LoadScene();
    Loop(sk, argc, argv);
    Shutdown();
    return 0;
}

