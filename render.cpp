#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

void render(SDL_Renderer* renderer) {
            // 1. Set the draw color (R, G, B, A) -> Let's go with a dark red
        SDL_SetRenderDrawColor(renderer, 150, 20, 20, 255);

        // 2. Clear the screen with that color
        SDL_RenderClear(renderer);

        // 3. Present the new frame to the window
        SDL_RenderPresent(renderer);
}