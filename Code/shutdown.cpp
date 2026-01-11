#include "engine_functions.h"

void Shutdown(Scene& scene, SDL_Window* window) {
    for (auto& obj : scene.gameObjects) {
        if (obj.texture) {
            SDL_DestroyTexture(obj.texture);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}