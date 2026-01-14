#include <map>
#include "SpriteAnimation.h"

class AnimationController {
public:
    std::map<std::string, SpriteAnimation> clips;
    SpriteAnimation* currentClip = nullptr;
    
    int currentFrameOffset = 0;
    float timer = 0.0f;

    void addClip(SpriteAnimation clip) {
        clips[clip.name] = clip;
        if (!currentClip) currentClip = &clips[clip.name];
    }

    void play(const std::string& name) {
        if (currentClip && currentClip->name == name) return;
        if (clips.find(name) != clips.end()) {
            currentClip = &clips[name];
            currentFrameOffset = 0;
            timer = 0.0f;
        }
    }

    void update(float deltaTime, int& outGlobalFrame) {
        if (!currentClip) return;

        timer += deltaTime;
        if (timer >= currentClip->frameDuration) {
            timer = 0.0f;
            currentFrameOffset++;

            if (currentFrameOffset >= currentClip->frameCount) {
                if (currentClip->loop) {
                    currentFrameOffset = 0;
                } else {
                    currentFrameOffset = currentClip->frameCount - 1;
                }
            }
        }
        outGlobalFrame = currentClip->startFrame + currentFrameOffset;
    }
};