#pragma once

#include "AppState.h"
#include "KeyboardHandler.h"
#include "Map.h"
#include "Ship.h"
#include "SailsController.h"
#include "NoAccelerationVelocityCalculator.h"
#include "ShipWithSailsMovementController.h"

#include <memory>

class AppStateTest : public AppState
{
public:
    //DEBUG VARS ONLY
    static int mPlayerX;
    static int mPlayerY;
    static bool mEnterPressed;
    KeyboardHandler mKeyboardHandler;
    Map mTestMap;
    std::unique_ptr <Ship> mPlayerShip;
    SailsController mTestSail;

    std::unique_ptr<ShipWithSailsMovementController> shipMovementController;
    NoAccelerationVelocityCalculator velCalc;

    SDL_Point lastMouseClick{ 0,0 };
private:
    static AppStateTest Instance;

private:
    AppStateTest();
    ~AppStateTest();

public:
    void OnKeyDown(SDL_Event* event);
    void OnKeyUp(SDL_Event* event) override;
    void OnLButtonDown(int mX, int mY) override;
    void OnResize(int w, int h) override;


    void Init(SDL_Renderer* Renderer);

    void OnActivate(SDL_Renderer* Renderer);

    void OnDeactivate();

    void OnLoop();

    void OnRender();
    static AppStateTest* GetInstance();
};