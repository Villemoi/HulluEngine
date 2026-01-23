#include "../Headers/engine_functions.h"

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
//Mouse
    void GetMousePosition(int& x, int& y) {
        SDL_GetMouseState(&x, &y);
    }

    bool IsMouseButtonDown(Uint8 button) {
        Uint32 buttons = SDL_GetMouseState(NULL, NULL);
        return (buttons & SDL_BUTTON(button)) != 0;
    }

}