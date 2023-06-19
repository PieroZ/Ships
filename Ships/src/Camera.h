#pragma once
#include <SDL.h>


enum
{
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class Camera
{
public:
    static Camera CameraControl;

private:
    double mX;
    double mY;
    int mCameraWidth;
    int mCameraHeight;

    double* TargetX;
    double* TargetY;

public:
    int TargetMode;

public:
    Camera();

public:
    void OnMove(double MoveX, double MoveY);

public:
    double GetX();
    double GetY();
    int GetCameraHeight() const;
    int GetCameraWidth() const;
    const SDL_Rect& GetCameraRect();

    void SetCameraWidth(int width);
    void SetCameraHeight(int height);

public:
    void SetPos(double x, double y);

    void SetTarget(double* x, double* y);
};