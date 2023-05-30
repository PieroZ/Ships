#include "AppStateTest.h"
#include "TextureBank.h"
#include "Log.h"
#include "Config.h"



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
	switch (event->key.keysym.sym)
	{
		case SDLK_LEFT:
		{
			mPlayerX--;
			break;
		}
		case SDLK_RIGHT:
		{
			mPlayerX++;
			break;
		}
		case SDLK_UP:
		{
			mPlayerY--;
			break;
		}
		case SDLK_DOWN:
		{
			mPlayerY++;
			break;
		}
	}
}
//------------------------------------

void AppStateTest::OnKeyUp(SDL_Event* Event)
{

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
}



void AppStateTest::OnRender()
{
	TextureBank::Get("homm2_testbg")->Render(0, 0, Config::getInstance().getScreenWidth(), Config::getInstance().getScreenHeight());
	TextureBank::Get("boat")->Render(mPlayerX, mPlayerY);
}



AppStateTest* AppStateTest::GetInstance()
{
	return &Instance;
}