#include "../Headers/engine_functions.h"

extern Shader* mainShader; 
extern Sprite* quadSprite;

void Shutdown(Scene& scene, SDL_Window* window, SDL_GLContext glContext) {

    for (auto& obj : scene.gameObjects) {
        if (obj.textureID != 0) {
            // OpenGL uses IDs (GLuint), not pointers
            glDeleteTextures(1, &obj.textureID);
        }
    }

    if (mainShader) {
        delete mainShader;
        mainShader = nullptr;
    }
    
    if (quadSprite) {
        delete quadSprite;
        quadSprite = nullptr;
    }

    if (glContext) {
        SDL_GL_DestroyContext(glContext);
    }

    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}