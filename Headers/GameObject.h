#ifndef OBJECT_H
#define OBJECT_H

#include <SDL3/SDL.h>
#include <string>

struct GameObject {
    int id;
    std::string name;
    unsigned int textureID = 0;
    struct {
        float x, y, z;
    } position = { 0.0f, 0.0f, 0.0f };
    struct {
        float w, h;
    } size = { 1.0f, 1.0f };
};

#endif