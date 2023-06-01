#include "AppStateTest.h"
#include "TextureBank.h"
#include "Log.h"
#include "Config.h"
#include "ScreenText.h"
#include "RenderQueue.h"
#include "App.h"
#include "Fonts.h"



AppStateTest AppStateTest::Instance;
int AppStateTest::mPlayerX = 500;
int AppStateTest::mPlayerY = 150;
bool AppStateTest::mEnterPressed = false;

AppStateTest::AppStateTest()
{
}
//------------------------------------

AppStateTest::~AppStateTest()
{
}

void AppStateTest::OnKeyDown(SDL_Event* event)
{
	//mKeyboardHandler.HandleKeyboardEvent(event);
}
//------------------------------------

void AppStateTest::OnLButtonDown(int x, int y)
{
	lastMouseClick.x = x;
	lastMouseClick.y = y;
	mTestMap.GetIdFromCoordinates(x, y);
}
void AppStateTest::OnKeyUp(SDL_Event* event)
{
	//mKeyboardHandler.HandleKeyboardEvent(event);
	if (event->key.keysym.sym == SDLK_RETURN || event->key.keysym.sym == SDLK_KP_ENTER)
	{
		const std::string& mapFile = "res/maps/2.map";
		mTestMap.OnLoad(mapFile, "ss_nomargin");
	}

}

void AppStateTest::OnResize(int w, int h)
{
	LOG_INFO("Window resized to {0}x{1}",w,h);
}


void AppStateTest::OnActivate(SDL_Renderer* Renderer)
{
	this->Renderer = Renderer;
	const std::string& mapFile = "res/maps/2.map";
	mTestMap.OnLoad(mapFile, "ss_nomargin");
}

void AppStateTest::OnDeactivate()
{
}

void AppStateTest::OnLoop()
{
	//if (mKeyboardHandler.IsPressed(SDLK_LEFT))
	//{
	//	mPlayerX--;
	//}
	//if (mKeyboardHandler.IsPressed(SDLK_RIGHT))
	//{
	//	mPlayerX++;
	//}
	//if (mKeyboardHandler.IsPressed(SDLK_UP))
	//{
	//	mPlayerY--;
	//}
	//if (mKeyboardHandler.IsPressed(SDLK_DOWN))
	//{
	//	mPlayerY++;
	//}
	//if (mKeyboardHandler.IsReleased(SDLK_KP_ENTER))
	//{
	//	LOG_INFO("Enter released!");
	//}

}



void AppStateTest::OnRender()
{
	//TextureBank::Get("bg_1920_1080")->RenderScaled(0, 0, App::GetInstance()->GetWindowWidth(), App::GetInstance()->GetWindowHeight(), mPlayerX/2, mPlayerY/2, TextureBank::Get("bg_1920_1080")->GetWidth()/2, TextureBank::Get("bg_1920_1080")->GetHeight()/2);

	mTestMap.AddToRenderQueue(0, 0);
	Texture screenText;
	std::string spritesCount = std::to_string(RenderQueue::GetInstance().GetSpritesCount());
	screenText.LoadText(Fonts::GetInstance().GetFont(), spritesCount, SDL_Color{ 255, 255, 255 });

	screenText.AddToRenderQueue(200, 200, screenText.GetWidth(), screenText.GetHeight(), 0, 0, screenText.GetWidth(), screenText.GetHeight(), 1);

	RenderQueue::GetInstance().Render();

	TextureBank::Get("biggerBoat")->RenderScaled(App::GetInstance()->GetWindowWidth()/2, App::GetInstance()->GetWindowHeight()/2);

	//std::string playerPosString = "mPlayerx = " + std::to_string(mPlayerX);
	//ScreenText::GetInstance().RenderText(playerPosString, 200, 200, SDL_Color{ 255, 0, 0 });

	//std::string lastMouseClickPos = std::to_string(lastMouseClick.x) + " " + std::to_string(lastMouseClick.y);
	//ScreenText::GetInstance().RenderText(lastMouseClickPos, 200, 200, SDL_Color{ 255, 255, 255 });


	//ScreenText::GetInstance().RenderText(spritesCount, 200, 200, SDL_Color{ 255, 255, 255 });


}



AppStateTest* AppStateTest::GetInstance()
{
	return &Instance;
}