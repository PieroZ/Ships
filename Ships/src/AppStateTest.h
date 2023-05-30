#pragma once

#include "AppState.h"

class AppStateTest : public AppState
{
private:
    static AppStateTest Instance;

private:
    AppStateTest();
    ~AppStateTest();

public:
    void OnKeyDown(SDL_Event* event);

    void OnKeyUp(SDL_Event* Event);

public:
    void Init(SDL_Renderer* Renderer);

    void OnActivate(SDL_Renderer* Renderer);

    void OnDeactivate();

    void OnLoop();

    void OnRender();

public:
    static AppStateTest* GetInstance();
};