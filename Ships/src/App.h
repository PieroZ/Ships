#pragma once

#include <SDL.h>

class App
{
private:
	static App mInstance;
	bool mRunning = true;

	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	SDL_Surface* mPrimarySurface = nullptr;

	static int mWindowWidth;
	static int mWindowHeight;
private:
	App();

	// Capture SDL Events
	void OnEvent(SDL_Event* Event);

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

};

