#ifndef SCENE_H
#define SCENE_H
#include "GameObject.h"
#include <vector>

struct Scene {
    std::vector<GameObject> gameObjects;
};

Scene LoadScene(); 

#endif