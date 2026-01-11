#include "engine_functions.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


int Loop(int argc, char* argv[]) {

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

    Scene scene = LoadScene(renderer);

    Uint64 lastTime = SDL_GetTicks();

    while (running) {

        Uint64 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        //logiikka
        Calculations(scene, deltaTime);

        //kuvan renderöinti
        Render(renderer, scene);
    }
    Shutdown(scene,window);
    return 0;
}