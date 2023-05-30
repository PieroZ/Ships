#pragma once

#include "AppState.h"
#include "KeyboardHandler.h"

class AppStateTest : public AppState
{
public:
    //DEBUG VARS ONLY
    static int mPlayerX;
    static int mPlayerY;
    KeyboardHandler mKeyboardHandler;
private:
    static AppStateTest Instance;

private:
    AppStateTest();
    ~AppStateTest();

public:
    void OnKeyDown(SDL_Event* event);
    void OnKeyUp(SDL_Event* event);

    void Init(SDL_Renderer* Renderer);

    void OnActivate(SDL_Renderer* Renderer);

    void OnDeactivate();

    void OnLoop();

    void OnRender();
    static AppStateTest* GetInstance();
};