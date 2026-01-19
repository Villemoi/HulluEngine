#include "../Headers/engine_functions.h"
#include <algorithm>

void CleanupScene(Scene* scene) {
    scene->gameObjects.erase(
        std::remove_if(scene->gameObjects.begin(), scene->gameObjects.end(),
            [](const std::unique_ptr<GameObject>& obj) {
                return obj->destroyed;
            }),
        scene->gameObjects.end()
    );
}