#include <unordered_map>
#include <string>
#include "GameObject.h"

class PrefabManager {
public:
    // Stores the "Blueprints"
    std::unordered_map<std::string, std::unique_ptr<GameObject>> prefabs;

    void addPrefab(const std::string& key, std::unique_ptr<GameObject> prefab) {
        prefabs[key] = std::move(prefab);
    }

    // Creates a fresh copy to put into the scene
    std::unique_ptr<GameObject> instantiate(const std::string& key) {
        if (prefabs.find(key) != prefabs.end()) {
            return prefabs[key]->clone();
        }
        return nullptr;
    }
};