#ifndef GAME_H
#define GAME_H
#include "Scene.h"
#include "PrefabManager.h"

struct Game {
    std::vector<std::unique_ptr<Scene>> scenes;
    std::unique_ptr<PrefabManager> prefabs;

    Game() : prefabs(std::make_unique<PrefabManager>()) {}
};

#endif