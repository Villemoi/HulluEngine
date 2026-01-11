#ifndef OBJECT_H
#define OBJECT_H

#include <SDL3/SDL.h>
#include <string>

struct GameObject {
    int id;
    std::string name;
    SDL_Texture* texture = nullptr;
    SDL_FRect transform = { 0, 0, 100, 100 }; // x, y, width, height
};

#endif