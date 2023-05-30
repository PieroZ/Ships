#pragma once

#include <SDL.h>
#include <unordered_map>


class KeyboardHandler
{
public:
    void HandleKeyboardEvent(SDL_Event* event);
    bool IsPressed(SDL_Keycode keycode);
    bool IsReleased(SDL_Keycode keycode);
private:
    std::unordered_map< SDL_Keycode, Uint32>  mKeyStateMap;
};