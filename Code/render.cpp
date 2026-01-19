#include "../Headers/engine_functions.h"
#include "../Headers/Shader.h"
#include "../Headers/Sprite.h"

Shader* mainShader = nullptr;
Sprite* quadSprite = nullptr;

void Render(SDL_Window* window, Scene& scene) {
    //Load shader
    if (!mainShader) {
        mainShader = new Shader("Shaders/default.vert", "Shaders/default.frag"); 
        quadSprite = new Sprite();
    }

    //Clear screen
    glClearColor(0.58f, 0.07f, 0.07f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Use the shader
    mainShader->use();
    
    glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
    mainShader->setMat4("projection", projection);

    //Draw every Game Object
    for (const auto& obj : scene.gameObjects) {
        if (obj->destroyed) continue;
        if (obj->textureID == 0) {
             SDL_Log("Object %s has no OpenGL texture loaded!", obj->name.c_str());
             continue;
        }

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(obj->position.x, obj->position.y, 0.0f));
        model = glm::scale(model, glm::vec3(obj->size.w, obj->size.h, 1.0f));
        
        mainShader->setMat4("model", model);

        float scaleX = 1.0f / obj->totalFramesInSheet; 
        glm::vec2 uScale = glm::vec2(scaleX, 1.0f);
        glm::vec2 uOffset = glm::vec2(obj->currentFrame * scaleX, 0.0f);

        mainShader->setVec2("uScale", glm::vec2(scaleX, 1.0f));
        mainShader->setVec2("uOffset", glm::vec2(obj->currentFrame * scaleX, 0.0f));

        glBindTexture(GL_TEXTURE_2D, obj->textureID);
        quadSprite->Draw();
    }
    
    //Swap to use the new window we just drew
    SDL_GL_SwapWindow(window);
}