#pragma once

#include "Texture.h"
#include "AbstractShipMovementController.h"
#include <memory>

class Ship
{
public:
    Ship(std::unique_ptr<AbstractShipMovementController> shipMovementController);
    ~Ship();
    void AddToRenderQueue(int renderOrder);
    void Move();

private:
    bool Init();
    bool LoadTexture();


private:
    std::unique_ptr<AbstractShipMovementController> mShipMovementController;
    Texture* mShipTexture = nullptr;

    inline static const std::string mShipTextureName = "mediumBoat";
    //int mX = 0;
    //int mY = 0;
    int mVelX = 0;
    int mVelY = 0;
    int mAccelX = 0;
    int mAccelY = 0;
    int mMaxSpeed = 0;
};

