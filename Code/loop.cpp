#include "../Headers/engine_functions.h"


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
    
    Scene scene = LoadScene(); 
    Uint64 lastTime = SDL_GetTicks();

    while (running) {
        Uint64 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        Calculations(scene, deltaTime);

        Render(window, scene);
    }

    Shutdown(scene, window, glContext);
    return 0;
}