#include "App.h"
#include "Log.h"

#include "TextureBank.h"

App App::mInstance;

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

	const char windowName[] = "RaceShips";

	if ((Window = SDL_CreateWindow(
		windowName,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
		) == NULL)
	{
		HZ_CORE_ERROR("Unable to create SDL Window: %s", SDL_GetError());
		return false;
	}

	PrimarySurface = SDL_GetWindowSurface(Window);

	if ((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
	{
		HZ_CORE_ERROR("Unable to create renderer");
		return false;
	}

	SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);

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

	return true;
}

//------------------------------------------------------------------------------
void App::Loop()
{
}

//------------------------------------------------------------------------------
void App::Render()
{
	SDL_RenderClear(Renderer);

	TextureBank::Get("sails")->Render(0, 0); // You should really check your pointers

	SDL_RenderPresent(Renderer);
}

//------------------------------------------------------------------------------
void App::Cleanup()
{
	TextureBank::Cleanup();

	if (Renderer)
	{
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if (Window)
	{
		SDL_DestroyWindow(Window);
		Window = NULL;
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
SDL_Renderer* App::GetRenderer() { return Renderer; }

//==============================================================================

int App::GetWindowWidth() { return WindowWidth; }
int App::GetWindowHeight() { return WindowHeight; }

//==============================================================================