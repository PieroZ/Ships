#pragma once
#include "Timer.h"
#include <sstream>

class FPS
{
public:
	static FPS& GetInstance();

	void StartFpsTimer();
	void StartCapTimer();
	void CalculateAndCorrectFps();
	void IncCountedFrames();
	void WaitIfRenderedEarly();
	void SetFpsText(float avgFps);
	std::string GetFpsString() const;
private:
	FPS();

private:

	//The frames per second timer
	Timer mFpsTimer;
	//The frames per second cap timer
	Timer mCapTimer;

	int mCountedFrames = 0;

	//In memory text stream
	std::stringstream mTimeText;

	static const int SCREEN_FPS = 60;
	static const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

};

