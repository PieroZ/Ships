#pragma once

#include "AppState.h"

enum
{
    // Add your Other App States Here
    APPSTATE_NONE,
    APPSTATE_TEST
};

class AppStateManager
{
private:
    static AppState* ActiveAppState;

public:
    static void OnEvent(SDL_Event* Event);

    static void OnLoop();

    static void OnRender();

public:
    static void SetActiveAppState(int AppStateID, SDL_Renderer* Renderer);

    static AppState* GetActiveAppState();
};