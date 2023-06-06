#include "Animation.h"

Animation::Animation()
{
    CurrentFrame = 0;
    mMaxFrames = 0;
    FrameInc = 1;

    FrameRate = 100; //Milliseconds
    OldTime = 0;

    Oscillate = false;
}

void Animation::OnAnimate()
{
    if (OldTime + FrameRate > SDL_GetTicks())
    {
        return;
    }

    OldTime = SDL_GetTicks();

    CurrentFrame += FrameInc;

    if (Oscillate)
    {
        if (FrameInc > 0)
        {
            if (CurrentFrame >= mMaxFrames)
            {
                FrameInc = -FrameInc;
            }
        }
        else
        {
            if (CurrentFrame <= 0)
            {
                FrameInc = -FrameInc;
            }
        }
    }
    else
    {
        if (CurrentFrame >= mMaxFrames)
        {
            CurrentFrame = 0;
        }
    }
}

void Animation::SetMaxFrames(int maxFrames)
{
    mMaxFrames = maxFrames;
}

void Animation::SetFrameRate(int Rate)
{
    FrameRate = Rate;
}

void Animation::SetCurrentFrame(int Frame)
{
    if (Frame < 0 || Frame >= mMaxFrames) return;

    CurrentFrame = Frame;
}

int Animation::GetCurrentFrame()
{
    return CurrentFrame;
}