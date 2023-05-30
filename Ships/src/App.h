#pragma once

#include <SDL.h>
#include "Event.h"

class App : public Event
{
private:
	static App mInstance;
	bool mRunning = true;

	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	SDL_Surface* mPrimarySurface = nullptr;

	static int mWindowWidth;
	static int mWindowHeight;

	static const int mTargetWidth = 1920;
	static const int mTargetHeight = 1080;
private:
	App();

	// Capture SDL Events
	void OnEvent(SDL_Event* Event);

	void OnKeyDown(SDL_Event* Event);
	void OnKeyUp(SDL_Event* Event);

	// Initialize our SDL game / app
	bool Init();
	void LoadWindowSizeFromConfig();

	// Logic loop
	void Loop();


	// Render loop (draw)
	void Render();

	// Free up resources
	void Cleanup();

public:

	int Execute(int argc, char* argv[]);

	static App* GetInstance();

	SDL_Renderer* GetRenderer();

	static int GetWindowWidth();
	static int GetWindowHeight();

	static int GetWindowTargetWidth();
	static int GetWindowTargetHeight();

};

