#ifndef OBJECT_H
#define OBJECT_H

#include <SDL3/SDL.h>
#include <string>
#include <vector>
#include <memory>

struct GameObject {
    int id;
    std::string name;
    unsigned int textureID = 0;

    int totalFrames = 4;
    int currentFrame = 0;
    float frameTimer = 0.0f;
    float frameDuration = 0.15f;

    struct Vector3{
        float x, y, z;
    } position = { 0.0f, 0.0f, 0.0f };
    struct {
        float w, h;
    } size = { 1.0f, 1.0f };

    GameObject* parent = nullptr;
    std::vector<std::unique_ptr<GameObject>> children;

    void addChild(std::unique_ptr<GameObject> child) {
        child->parent = this;
        children.push_back(std::move(child));
    }

    Vector3 getWorldPosition() const {
        if (parent) {
            Vector3 parentWorldPos = parent->getWorldPosition();
            return {
                position.x + parentWorldPos.x,
                position.y + parentWorldPos.y,
                position.z + parentWorldPos.z
            };
        }
        return position; // Root objects return their local position
    }
};

#endif