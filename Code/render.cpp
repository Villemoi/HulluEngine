#include "../Headers/engine_functions.h"

void Render(SDL_Renderer* renderer, Scene& scene) {
        SDL_SetRenderDrawColor(renderer, 150, 20, 20, 255);
    SDL_RenderClear(renderer);

    for (const auto& obj : scene.gameObjects) {
        if (obj.texture != nullptr) {
            SDL_RenderTexture(renderer, obj.texture, NULL, &obj.transform);
        }else {
            SDL_Log("Object %s has a NULL texture!", obj.name.c_str());
        }
    }

    SDL_RenderPresent(renderer);
}