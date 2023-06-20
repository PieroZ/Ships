#include "Camera.h"
#include "App.h"
#include <algorithm>

Camera Camera::CameraControl;

Camera::Camera()
{
    mX = mY = 0;

    TargetX = TargetY = NULL;

    TargetMode = TARGET_MODE_NORMAL;
}

void Camera::OnMove(double deltaX, double deltaY)
{
    mX += deltaX;
    mY += deltaY;

    mX = std::max(*TargetX - mCameraWidth / 2, 0.0);
    if (mX)
    {
        mX = std::min(*TargetX - mCameraWidth / 2, static_cast<double>(mLevelWidth - mCameraWidth));
    }

    mY = std::max(*TargetY - mCameraHeight / 2, 0.0);
    if (mY)
    {
        mY = std::min(*TargetY - mCameraHeight / 2, static_cast<double>(mLevelHeight - mCameraHeight));
    }
}

double Camera::GetX()
{
    if (TargetX != NULL)
    {
        if (TargetMode == TARGET_MODE_CENTER)
        {
            return *TargetX - (App::GetInstance()->GetWindowWidth() / 2);
        }

        return *TargetX;
    }

    return mX;
}

double Camera::GetY()
{
    if (TargetY != NULL)
    {
        if (TargetMode == TARGET_MODE_CENTER)
        {
            return *TargetY - (App::GetInstance()->GetWindowHeight() / 2);
        }

        return *TargetY;
    }

    return mY;
}

int Camera::GetCameraHeight() const
{
    return mCameraHeight;
}

int Camera::GetCameraWidth() const
{
    return mCameraWidth;
}

const SDL_Rect& Camera::GetCameraRect()
{
    return {static_cast<int>(mX), static_cast<int>(mY), mCameraWidth, mCameraHeight };
}

void Camera::SetCameraWidth(int width)
{
    mCameraWidth = width;
}

void Camera::SetCameraHeight(int height)
{
    mCameraHeight = height;
}

void Camera::SetPos(double x, double y)
{
    this->mX = x;
    this->mY = y;
}

void Camera::SetLevelLimits(int levelWidth, int levelHeight)
{
    mLevelWidth = levelWidth;
    mLevelHeight = levelHeight;
}

void Camera::SetTarget(double* x, double* y)
{
    TargetX = x;
    TargetY = y;

    mX = static_cast<int>(*TargetX) - mCameraWidth / 2;
    mY = static_cast<int>(*TargetY) - mCameraHeight / 2;
}