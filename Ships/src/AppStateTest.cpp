#include "AppStateTest.h"
#include "TextureBank.h"
#include "Log.h"
#include "Config.h"
#include "ScreenText.h"
#include "App.h"




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

void AppStateTest::OnResize(int w, int h)
{
	LOG_INFO("Window resized to {0}x{1}",w,h);
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
	TextureBank::Get("bg_1920_1080")->RenderScaled(0, 0, App::GetInstance()->GetWindowWidth(), App::GetInstance()->GetWindowHeight(), mPlayerX/2, mPlayerY/2, TextureBank::Get("bg_1920_1080")->GetWidth()/2, TextureBank::Get("bg_1920_1080")->GetHeight()/2);
	TextureBank::Get("biggerBoat")->RenderScaled(App::GetInstance()->GetWindowWidth()/2, App::GetInstance()->GetWindowHeight()/2);

	std::string playerPosString = "mPlayerx = " + std::to_string(mPlayerX);

	ScreenText::GetInstance().RenderText(playerPosString, 200, 200, SDL_Color{ 255, 0, 0 });
}



AppStateTest* AppStateTest::GetInstance()
{
	return &Instance;
}