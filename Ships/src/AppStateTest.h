#pragma once

#include "AppState.h"
#include "KeyboardHandler.h"
#include "Map.h"
#include "Ship.h"
#include "ShipWithEngineMovementController.h"
#include "NoAccelerationVelocityCalculator.h"
#include "ShipMovementInterface.h"
#include "TargetWaypoint.h"
#include "TargetWaypointsDisplay.h"

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

    std::vector<std::shared_ptr<TargetWaypoint>> mTargetWaypoints;
    //TargetWaypointsDisplay mAITargetWaypointsDisplay;
    TargetWaypointsDisplay mTargetWaypointsDisplay;
//    std::shared_ptr <Ship> mPlayerShip;
    Ship* mPlayerShip;
    Ship* mAIShip;

    //std::unique_ptr<ShipWithEngineMovementController> mPlayerMovementController;
    //std::unique_ptr<ShipWithEngineMovementController> mAIShipMovementController;

    ShipWithEngineMovementController* mPlayerMovementController;
    ShipWithEngineMovementController* mAIShipMovementController;

    std::unique_ptr <NoAccelerationVelocityCalculator> mVelCalc;

    std::unique_ptr <NoAccelerationVelocityCalculator> mThisShouldNotBeAUniquePtrCalc;

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
    void SetupTargetWaypoints();

    void OnActivate(SDL_Renderer* Renderer);

    void OnDeactivate();

    void OnLoop();

    void OnRender();
    void DebugTextRender();
    static AppStateTest* GetInstance();
};