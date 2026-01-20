#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Scene.h"

class SceneManager {
private:
    std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
    Scene* activeScene = nullptr;

public:

    SceneManager() = default;

    void addScene(const std::string& name, std::unique_ptr<Scene> scene) {
        scenes[name] = std::move(scene);
        // If it's the first scene added, make it active by default
        if (activeScene == nullptr) {
            activeScene = scenes[name].get();
        }
    }

    void loadScene(const std::string& name) {
        if (scenes.find(name) != scenes.end()) {
            activeScene = scenes[name].get();
        }
    }

    Scene* getActiveScene() const {
        return activeScene;
    }
};

#endif