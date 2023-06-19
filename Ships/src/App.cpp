#include <SDL_ttf.h>

#include "App.h"
#include "Log.h"
#include "Config.h"

#include "TextureBank.h"
#include "AppStateManager.h"
#include "Fonts.h"
#include "FPS.h"

App App::mInstance;
int App::mWindowWidth = 1024;
int App::mWindowHeight = 768;

App::App()
{
	Ships::Log::Init();
}


App* App::GetInstance()
{
	return &App::mInstance;
}

//------------------------------------------------------------------------------
void App::OnKeyDown(SDL_Event* Event)
{

}
//------------------------------------------------------------------------------
void App::OnKeyUp(SDL_Event* Event)
{

}

//------------------------------------------------------------------------------
void App::OnEvent(SDL_Event* Event)
{
	Event::OnEvent(Event);
	AppStateManager::OnEvent(Event);
}
//------------------------------------------------------------------------------
void App::LoadWindowSizeFromConfig()
{
	mWindowWidth = Config::getInstance().getScreenWidth();
	mWindowHeight = Config::getInstance().getScreenHeight();
}
//------------------------------------------------------------------------------
bool App::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG_ERROR("Unable to Init SDL: {0}", SDL_GetError());
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		LOG_ERROR("Unable to Init hinting: {0}", SDL_GetError());
	}

	LoadWindowSizeFromConfig();

	const char windowName[] = "RaceShips";
	Uint32 flags = (SDL_WINDOW_SHOWN);
	//Uint32 flags = (SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);

	if ((mWindow = SDL_CreateWindow(
		windowName,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		mWindowWidth, mWindowHeight, flags)
		//mWindowWidth, mWindowHeight, (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE))
		) == NULL)
	{
		LOG_ERROR("Unable to create SDL Window: {0}", SDL_GetError());
		return false;
	}

	mPrimarySurface = SDL_GetWindowSurface(mWindow);

	if ((mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED)) == NULL)
	{
		LOG_ERROR("Unable to create renderer");
		return false;
	}

	// TEST
	SDL_RenderSetVSync(mRenderer, 1);

	SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);

	// Initialize image loading for PNGs
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		LOG_ERROR("Unable to init SDL_image: {0}", IMG_GetError());
		return false;
	}

	// Load all of our Textures (see TextureBank class for expected folder)
	if (TextureBank::Init() == false)
	{
		LOG_ERROR("Unable to init TextureBank");
		return false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		LOG_ERROR("SDL_ttf could not initialize! SDL_ttf Error: {0}\n", TTF_GetError());
		return false;
	}

	if(!Fonts::GetInstance().Init())
	{
		LOG_ERROR("Fonts could not initialize!");
		return false;
	}

	AppStateManager::SetActiveAppState(APPSTATE_TEST, mRenderer);


	return true;
}

//------------------------------------------------------------------------------
void App::Loop()
{
	AppStateManager::OnLoop();
}

//------------------------------------------------------------------------------
void App::Render()
{
	SDL_RenderClear(mRenderer);

	AppStateManager::OnRender();

	SDL_RenderPresent(mRenderer);
}

//------------------------------------------------------------------------------
void App::Cleanup()
{
	TextureBank::Cleanup();
	Fonts::GetInstance().Cleanup();

	if (mRenderer)
	{
		SDL_DestroyRenderer(mRenderer);
		mRenderer = nullptr;
	}

	if (mWindow)
	{
		SDL_DestroyWindow(mWindow);
		mWindow = nullptr;
	}

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

int App::Execute(int argc, char* argv[])
{
	if (!Init())
	{
		return 0;
	}
	auto& fps = FPS::GetInstance();

	SDL_Event Event;

	fps.StartFpsTimer();

	while (mRunning)
	{
		//Start cap timer
		fps.StartCapTimer();
		while (SDL_PollEvent(&Event) != 0)
		{
			OnEvent(&Event);

			if (Event.type == SDL_QUIT)
			{
				mRunning = false;
			}
		}
		
		fps.CalculateAndCorrectFps();

		Loop();
		Render();
		fps.IncCountedFrames();

		fps.WaitIfRenderedEarly();

		//SDL_Delay(1); // Breath
	}

	Cleanup();

	return 1;
}

//==============================================================================
SDL_Renderer* App::GetRenderer() { return mRenderer; }

//==============================================================================

int App::GetWindowWidth() { return mWindowWidth; }
int App::GetWindowHeight() { return mWindowHeight; }
int App::GetWindowTargetWidth() { return mTargetWidth; }
int App::GetWindowTargetHeight() { return mTargetHeight; }

//==============================================================================