#ifndef SCENE_H
#define SCENE_H
#include "object.h"

struct Scene {
    Object object1;
    Object object2;
};

// Declare the function so other files know it exists
Scene LoadScene(); 

#endif