#ifndef SPRITE_H
#define SPRITE_H

#include <GL/glew.h>

class Sprite {
public:
    unsigned int VAO, VBO;
    Sprite();
    ~Sprite();
    void Draw();
};

#endif