#include "../Classes/scene.h"
#include <SDL3/SDL_video.h>

void Shutdown(Scene& scene, SDL_Window* window) {
    for (auto& obj : scene.gameObjects) {
        if (obj.texture) {
            SDL_DestroyTexture(obj.texture);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}