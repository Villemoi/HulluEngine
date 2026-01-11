#ifndef ENGINE_FUNCTIONS_H
#define ENGINE_FUNCTIONS_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include "../Classes/scene.h"

// From start.cpp
Scene LoadScene(SDL_Renderer* renderer); //

// From loop.cpp
int Loop(int argc, char* argv[]); //

// From render.cpp
void Render(SDL_Renderer* renderer, Scene& scene); //

// From calculations.cpp
// Note: Changed to pass by reference (Scene& scene) to fix the logic bug
void Calculations(Scene& scene, float deltaTime); //

// From inputs.cpp
namespace Input {
    bool IsKeyDown(SDL_Scancode key);
}

// From shutdown.cpp
void Shutdown(Scene& scene, SDL_Window* window); //

#endif