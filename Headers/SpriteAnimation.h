#ifndef SPRITE_ANIMATION_H
#define SPRITE_ANIMATION_H

#include <string>

struct SpriteAnimation {
    std::string name;
    int startFrame;
    int frameCount;
    float frameDuration;
    bool loop = true;
};

#endif