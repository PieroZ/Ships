#include "AppStateTest.h"
#include "TextureBank.h"
#include "Log.h"
#include "Config.h"
#include "ScreenText.h"




// The solution is to ensure that all virtual methods that are not pure are defined. Note that a destructor must be defined even if it is declared pure-virtual

AppStateTest AppStateTest::Instance;
int AppStateTest::mPlayerX = 500;
int AppStateTest::mPlayerY = 150;

AppStateTest::AppStateTest()
{
}
//------------------------------------

AppStateTest::~AppStateTest()
{
}

void AppStateTest::OnKeyDown(SDL_Event* event)
{
	mKeyboardHandler.HandleKeyboardEvent(event);
}
//------------------------------------

void AppStateTest::OnKeyUp(SDL_Event* event)
{
	mKeyboardHandler.HandleKeyboardEvent(event);

}


void AppStateTest::OnActivate(SDL_Renderer* Renderer)
{
	this->Renderer = Renderer;
}

void AppStateTest::OnDeactivate()
{
}

void AppStateTest::OnLoop()
{
	if (mKeyboardHandler.IsPressed(SDLK_LEFT))
	{
		mPlayerX--;
	}
	if (mKeyboardHandler.IsPressed(SDLK_RIGHT))
	{
		mPlayerX++;
	}
	if (mKeyboardHandler.IsPressed(SDLK_UP))
	{
		mPlayerY--;
	}
	if (mKeyboardHandler.IsPressed(SDLK_DOWN))
	{
		mPlayerY++;
	}
}



void AppStateTest::OnRender()
{
	TextureBank::Get("homm2_testbg")->Render(0, 0, Config::getInstance().getScreenWidth(), Config::getInstance().getScreenHeight());
	TextureBank::Get("boat")->Render(mPlayerX, mPlayerY);

	ScreenText::GetInstance().RenderText("Screen text", 200, 200, SDL_Color{ 255, 0, 0 });
}



AppStateTest* AppStateTest::GetInstance()
{
	return &Instance;
}