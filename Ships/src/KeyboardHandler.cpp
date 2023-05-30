#include "KeyboardHandler.h"


void KeyboardHandler::HandleKeyboardEvent(SDL_Event* event)
{
    mKeyStateMap[event->key.keysym.sym] = event->type;
}

bool KeyboardHandler::IsPressed(SDL_Keycode keycode)
{
    return (mKeyStateMap[keycode] == SDL_KEYDOWN);
}

bool KeyboardHandler::IsReleased(SDL_Keycode keycode)
{
    return (mKeyStateMap[keycode] == SDL_KEYUP);
}