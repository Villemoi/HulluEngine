#include "classes.h"
#include "inputs.cpp"
#include "render.cpp"
#include "calculations.cpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int loop(skene skene, int argc, char* argv[]) {

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!SDL_CreateWindowAndRenderer("HulluEngine", 800, 600, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return 1;
    }

    bool running = true;
    SDL_Event event;

    int counter = 0;

    while (running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        //logiikka
        calculations(skene);

        //kuvan renderöinti
        render(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}