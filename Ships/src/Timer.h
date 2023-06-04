#pragma once

#include <cstdio>

class Timer
{
public:
	//Initializes variables
	Timer();

	//The various clock actions
	void Start();
	void Stop();
	void Pause();
	void Unpause();

	//Gets the timer's time
	unsigned int GetTicks();

	//Checks the status of the timer
	bool IsStarted();
	bool IsPaused();

private:
	//The clock time when the timer started
	unsigned int mStartTicks;

	//The ticks stored when the timer was paused
	unsigned int mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;
};

