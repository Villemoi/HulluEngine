#ifndef GAME_H
#define GAME_H
#include "SceneManager.h"
#include "PrefabManager.h"
#include <memory>

struct Game {
    std::unique_ptr<SceneManager> sceneManager;
    std::unique_ptr<PrefabManager> prefabs;

    Game() : 
        sceneManager(std::make_unique<SceneManager>()),
        prefabs(std::make_unique<PrefabManager>()){}
};

#endif