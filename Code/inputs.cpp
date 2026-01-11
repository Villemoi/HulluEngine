#include <SDL3/SDL.h>

namespace Input {
    const bool* GetKeyState() {
        return SDL_GetKeyboardState(NULL);
    }

    bool IsKeyDown(SDL_Scancode key) {
        const bool* state = GetKeyState();
        if (state != nullptr) {
            return state[key];
        }
        return false;
    }
}