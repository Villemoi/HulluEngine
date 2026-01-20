#include "../Headers/engine_functions.h"
#include <SDL3/SDL_log.h>


int Loop(int argc, char* argv[]) {
    //Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    //Load OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    //Create Window
    SDL_Window* window = SDL_CreateWindow("HulluEngine 2.5D", 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return 1;
    }

    //Create context for OpenGL
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        SDL_Log("OpenGL Context creation failed: %s", SDL_GetError());
        return 1;
    }

    //Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        SDL_Log("Failed to initialize GLEW");
        return 1;
    }

    //Enable OpenGL
    glEnable(GL_DEPTH_TEST);

    bool running = true;
    SDL_Event event;
    Game game = LoadGame();
    SceneManager* sceneManager = game.sceneManager.get();
    PrefabManager* prefabManager = game.prefabs.get();
    Uint64 lastTime = SDL_GetTicks();
    SDL_Log("starting loop!");
    while (running) {

        Scene* currentScene = sceneManager->getActiveScene();

        Uint64 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        SDL_Log("delta time calculated");
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        if(currentScene){
            SDL_Log("doing calculations");
            Calculations(currentScene, deltaTime, prefabManager, sceneManager);

            //Delete all GameObjects that have been marked for deletion
            SDL_Log("cleaning up the scene");
            CleanupScene(currentScene);

            SDL_Log("rendering the scene");
            Render(window, currentScene);
        }else{
        // Clear the screen to black so we know the window is alive
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
        }
    }
    Shutdown(sceneManager->getActiveScene(), window, glContext);
    return 0;
}