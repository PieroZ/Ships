#pragma once

#include "Texture.h"

class Ship
{
public:
    Ship();
    void Render(int x, int y);

private:
    bool Init();
    bool LoadTexture();


private:
    Texture* mShipTexture = nullptr;

    inline static const std::string mShipTextureName = "biggerBoat";
    int mX = 0;
    int mY = 0;
    int mVelX = 0;
    int mVelY = 0;
    int mAccelX = 0;
    int mAccelY = 0;
    int mMaxSpeed = 0;
};

