#include "../Headers/engine_functions.h"

void Calculations(Scene* scene, float deltaTime, PrefabManager* prefabManager, SceneManager* sceneManager) {
    if (!scene->gameObjects.empty()) {

        //this handles the player animation
        if (scene->gameObjects[0]->animator) {
            scene->gameObjects[0]->animator->update(deltaTime, scene->gameObjects[0]->currentFrame);
        }

        bool isMoving = Input::IsKeyDown(SDL_SCANCODE_W) ||
                        Input::IsKeyDown(SDL_SCANCODE_S) ||
                        Input::IsKeyDown(SDL_SCANCODE_A) ||
                        Input::IsKeyDown(SDL_SCANCODE_D);
        if (isMoving) {
            scene->gameObjects[0]->animator->play("Walk");
        } else {
            scene->gameObjects[0]->animator->play("Idle");
        }

        //this handles the slime animation
        for (auto& obj : scene->gameObjects) {
            if (obj->name == "Slime_clone") {
                obj->animator->play("Bounce");
            }
        }

        //this handles the movement
        float speed = 300.0f;
        float moveStep = speed * deltaTime;

        if (Input::IsKeyDown(SDL_SCANCODE_W)) scene->gameObjects[0]->position.y -= moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_S)) scene->gameObjects[0]->position.y += moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_A)) scene->gameObjects[0]->position.x -= moveStep;
        if (Input::IsKeyDown(SDL_SCANCODE_D)) scene->gameObjects[0]->position.x += moveStep;

        //Spawn slime when spacebar is pressed
        if (Input::IsKeyDown(SDL_SCANCODE_SPACE)) {
            auto newEnemy = prefabManager->instantiate("Slime");
            if (newEnemy) {
                newEnemy->position = { 400.0f, 300.0f, 0.0f }; // Set specific spawn location
                scene->gameObjects.push_back(std::move(newEnemy));
            }
        }

        //Destroy all slimes when pressing 'K'
        if (Input::IsKeyDown(SDL_SCANCODE_K)) {
            for (auto& obj : scene->gameObjects) {
                if (obj->name == "Slime_clone") {
                    obj->destroy();
                }
            }
        }

        if (Input::IsKeyDown(SDL_SCANCODE_1)) {
            sceneManager->loadScene("Level1");
        }
        if (Input::IsKeyDown(SDL_SCANCODE_2)) {
            sceneManager->loadScene("Level2");
        }
    }
}