#pragma once

#include "Texture.h"
#include "ShipWithEngineMovementController.h"
#include "Animation.h"
#include "AnimatedTexture.h"
//#include "TargetWaypoint.h"
#include <memory>

enum ShipRotation
{
    none,
    clockwise,
    counterclockwise
};

class Ship
{
public:
    //Ship(std::unique_ptr<ShipWithEngineMovementController> mPlayerMovementController);
    Ship(ShipWithEngineMovementController* mPlayerMovementController);
    ~Ship();
    void AddToRenderQueue(int renderOrder, SDL_Color c = {0, 0 ,0});
    int Move();
    void SetClockwiseRotation();
    void SetCounterclockwiseRotation();
    void SetTargetWaypoint();
    void StopRotate();
    void Rotate();
    double* GetX();
    double* GetY();
    

    void OnWKeyAction();
    void OnDKeyAction();
    void OnSKeyAction();
    void OnAKeyAction();

    std::string ToText();


private:
    bool Init();
    bool LoadTexture();


private:
    //std::unique_ptr<ShipWithEngineMovementController> mPlayerMovementController;
    ShipWithEngineMovementController* mPlayerMovementController;
    std::unique_ptr<AnimatedTexture> mAnimation;
    //std::shared_ptr<TargetWaypoint> mCurrentTargetWaypoint;
    Texture* mShipTexture = nullptr;

    //inline static const std::string mShipTextureName = "floss-move-with-sail-blue";
    inline static const std::string mShipTextureName = "myTestBoat";
    //int mX = 0;
    //int mY = 0;
    int mVelX = 0;
    int mVelY = 0;
    int mAccelX = 0;
    int mAccelY = 0;
    int mMaxSpeed = 0;
    enum ShipRotation mShipRotation = ShipRotation::none;
};

