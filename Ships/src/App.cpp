#include "App.h"
#include "Log.h"
#include "Config.h"

#include "TextureBank.h"
#include "AppStateManager.h"

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
void App::OnEvent(SDL_Event* Event)
{
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
		HZ_CORE_ERROR("Unable to Init SDL: %s", SDL_GetError());
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		HZ_CORE_ERROR("Unable to Init hinting: %s", SDL_GetError());
	}

	LoadWindowSizeFromConfig();

	const char windowName[] = "RaceShips";

	if ((mWindow = SDL_CreateWindow(
		windowName,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		mWindowWidth, mWindowHeight, SDL_WINDOW_SHOWN)
		) == NULL)
	{
		HZ_CORE_ERROR("Unable to create SDL Window: %s", SDL_GetError());
		return false;
	}

	mPrimarySurface = SDL_GetWindowSurface(mWindow);

	if ((mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED)) == NULL)
	{
		HZ_CORE_ERROR("Unable to create renderer");
		return false;
	}

	SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);

	// Initialize image loading for PNGs
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		HZ_CORE_ERROR("Unable to init SDL_image: %s", IMG_GetError());
		return false;
	}

	// Load all of our Textures (see TextureBank class for expected folder)
	if (TextureBank::Init() == false)
	{
		HZ_CORE_ERROR("Unable to init TextureBank");
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
	SDL_Quit();
}

int App::Execute(int argc, char* argv[])
{
	if (!Init())
	{
		return 0;
	}

	SDL_Event Event;

	while (mRunning)
	{
		while (SDL_PollEvent(&Event) != 0)
		{
			OnEvent(&Event);

			if (Event.type == SDL_QUIT)
			{
				mRunning = false;
			}
		}

		Loop();
		Render();

		SDL_Delay(1); // Breath
	}

	Cleanup();

	return 1;
}

//==============================================================================
SDL_Renderer* App::GetRenderer() { return mRenderer; }

//==============================================================================

int App::GetWindowWidth() { return mWindowWidth; }
int App::GetWindowHeight() { return mWindowHeight; }

//==============================================================================