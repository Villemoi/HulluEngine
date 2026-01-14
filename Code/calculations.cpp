#include "../Headers/engine_functions.h"

void Calculations(Scene& scene, float deltaTime) {
    if (!scene.gameObjects.empty()) {

        //this handles the animation
        if (scene.gameObjects[0]->animator) {
            scene.gameObjects[0]->animator->update(deltaTime, scene.gameObjects[0]->currentFrame);
        }

        bool isMoving = Input::IsKeyDown(SDL_SCANCODE_W) ||
                        Input::IsKeyDown(SDL_SCANCODE_S) ||
                        Input::IsKeyDown(SDL_SCANCODE_A) ||
                        Input::IsKeyDown(SDL_SCANCODE_D);
        if (isMoving) {
            scene.gameObjects[0]->animator->play("Walk");
        } else {
            scene.gameObjects[0]->animator->play("Idle");
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