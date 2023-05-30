#pragma once

#include <SDL.h>

class App
{
private:
	static App mInstance;
	bool mRunning = true;

	SDL_Window* Window = NULL;
	SDL_Renderer* Renderer = NULL;
	SDL_Surface* PrimarySurface = NULL;

	static const int WindowWidth = 1024;
	static const int WindowHeight = 768;
private:
	App();

	// Capture SDL Events
	void OnEvent(SDL_Event* Event);

	// Initialize our SDL game / app
	bool Init();

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

