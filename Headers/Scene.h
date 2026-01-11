#ifndef SCENE_H
#define SCENE_H
#include "GameObject.h"
#include <vector>

struct Scene {
    std::vector<GameObject> gameObjects;
};

// Declare the function so other files know it exists
Scene LoadScene(); 

#endif