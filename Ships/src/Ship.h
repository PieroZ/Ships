#pragma once

#include "Texture.h"
#include "AbstractShipMovementController.h"
#include "Animation.h"
#include "AnimatedTexture.h"
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
    Ship(std::unique_ptr<AbstractShipMovementController> mShipMovementController);
    ~Ship();
    void AddToRenderQueue(int renderOrder);
    void Move();
    void SetClockwiseRotation();
    void SetCounterclockwiseRotation();
    void StopRotate();
    void Rotate();

    void OnWKeyAction();
    void OnSKeyAction();

    std::string ToText();


private:
    bool Init();
    bool LoadTexture();


private:
    std::unique_ptr<AbstractShipMovementController> mShipMovementController;
    std::unique_ptr<AnimatedTexture> mAnimation;
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

