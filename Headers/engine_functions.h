#ifndef ENGINE_FUNCTIONS_H
#define ENGINE_FUNCTIONS_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_main.h>
#include "Scene.h"

Scene LoadScene(SDL_Renderer* renderer);

int Loop(int argc, char* argv[]);

void Render(SDL_Renderer* renderer, Scene& scene);

void Calculations(Scene& scene, float deltaTime);

namespace Input {
    bool IsKeyDown(SDL_Scancode key);
}

void Shutdown(Scene& scene, SDL_Window* window);

#endif