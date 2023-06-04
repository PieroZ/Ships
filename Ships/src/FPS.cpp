#include "FPS.h"
#include <SDL.h>

FPS& FPS::GetInstance()
{
	static FPS instance;
	return instance;
}

void FPS::StartFpsTimer()
{
	mFpsTimer.Start();
}

void FPS::StartCapTimer()
{
	mCapTimer.Start();
}

void FPS::CalculateAndCorrectFps()
{
	//Calculate and correct fps
	float avgFPS = mCountedFrames / (mFpsTimer.GetTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}
	SetFpsText(avgFPS);
}

void FPS::IncCountedFrames()
{
	mCountedFrames++;
}

void FPS::WaitIfRenderedEarly()
{
	//If frame finished early
	int frameTicks = mCapTimer.GetTicks();
	if (frameTicks < SCREEN_TICK_PER_FRAME)
	{
		//Wait remaining time
		SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
	}
}

void FPS::SetFpsText(float avgFps)
{
	//Set text to be rendered
	mTimeText.str("");
	mTimeText << "Average Frames Per Second (With Cap) " << avgFps;
}

std::string FPS::GetFpsString() const
{
	return mTimeText.str();
}

FPS::FPS()
{
}
