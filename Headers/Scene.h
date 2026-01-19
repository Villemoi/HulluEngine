#ifndef SCENE_H
#define SCENE_H
#include "GameObject.h"
#include <vector>
#include "../Headers/PrefabManager.h"

struct Scene {
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    std::unique_ptr<PrefabManager> prefabs;

    Scene() : prefabs(std::make_unique<PrefabManager>()) {}
};

Scene LoadScene(); 

#endif