#include "../Headers/engine_functions.h"

void Calculations(Scene& scene, float deltaTime) {
    if (!scene.gameObjects.empty()) {
        float speed = 300.0f;
        float moveStep = speed * deltaTime;

        if (Input::IsKeyDown(SDL_SCANCODE_W)) scene.gameObjects[0].transform.y -= moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_S)) scene.gameObjects[0].transform.y += moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_A)) scene.gameObjects[0].transform.x -= moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_D)) scene.gameObjects[0].transform.x += moveStep;
    }
}