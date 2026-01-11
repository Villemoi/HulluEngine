#include <SDL3/SDL.h>

namespace Input {
    // This returns a pointer to the internal SDL keyboard state array
    // SDL manages this memory, so we don't need to delete it
    const bool* GetKeyState() {
        return SDL_GetKeyboardState(NULL);
    }

    // A helper function to make it easier for scripts to read
    bool IsKeyDown(SDL_Scancode key) {
        const bool* state = GetKeyState();
        if (state != nullptr) {
            return state[key];
        }
        return false;
    }
}