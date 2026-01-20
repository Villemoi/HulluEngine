#ifndef ENGINE_FUNCTIONS_H
#define ENGINE_FUNCTIONS_H

#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_opengl.h>
#include "Scene.h"
#include "Game.h"
#include "SceneManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Scene LoadScene();

Scene LoadScene2();

Game LoadGame();

int Loop(int argc, char* argv[]);

void Render(SDL_Window* window, Scene* scene);

void Calculations(Scene* scene, float deltaTime, PrefabManager* prefabManager, SceneManager* sceneManager);

namespace Input {
    bool IsKeyDown(SDL_Scancode key);
}

void Shutdown(Scene* scene, SDL_Window* window, SDL_GLContext glContext);

void CleanupScene(Scene* scene);

#endif