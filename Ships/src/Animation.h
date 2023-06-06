#pragma once
#include <SDL.h>

class Animation
{
private:
	int    CurrentFrame;

	int     FrameInc;

	int    mMaxFrames;

private:
	int     FrameRate; //Milliseconds

	long    OldTime;

public:

	bool    Oscillate;

public:
	Animation();

	void OnAnimate();

public:

	void SetMaxFrames(int maxFrames);
	void SetFrameRate(int Rate);

	void SetCurrentFrame(int Frame);

	int GetCurrentFrame();
};