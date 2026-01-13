#include "../Headers/engine_functions.h"

void Calculations(Scene& scene, float deltaTime) {
    if (!scene.gameObjects.empty()) {

        //this handles the animation
        scene.gameObjects[0]->frameTimer += deltaTime;
        if (scene.gameObjects[0]->frameTimer >= scene.gameObjects[0]->frameDuration) {
            scene.gameObjects[0]->currentFrame = (scene.gameObjects[0]->currentFrame + 1) % scene.gameObjects[0]->totalFrames;
            scene.gameObjects[0]->frameTimer = 0.0f;
        }

        //this handles the movement
        float speed = 300.0f;
        float moveStep = speed * deltaTime;

        if (Input::IsKeyDown(SDL_SCANCODE_W)) scene.gameObjects[0]->position.y -= moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_S)) scene.gameObjects[0]->position.y += moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_A)) scene.gameObjects[0]->position.x -= moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_D)) scene.gameObjects[0]->position.x += moveStep;
    }
}