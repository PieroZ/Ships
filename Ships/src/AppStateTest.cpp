#include "AppStateTest.h"
#include "TextureBank.h"
#include "Log.h"
#include "Config.h"
#include "RenderQueue.h"
#include "App.h"
#include "Fonts.h"
#include "FPS.h"
#include "Camera.h"

#include "AIGotoTargetASAPController.h"
#include "ShipWithSailsMovementController.h"
#include "ShipWithEngineMovementController.h"
#include "TargetWaypointBrowser.h"
#include "PlayerShipController.h"

#include <random>


AppStateTest AppStateTest::Instance;
int AppStateTest::mPlayerX = 500;
int AppStateTest::mPlayerY = 150;
bool AppStateTest::mEnterPressed = false;

static const int WAYPOINTS_COUNT = 10;

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


	//if (event->key.keysym.sym == SDLK_r)
	//{
	//	mPlayerShip->SetClockwiseRotation();
	//}
	//else if (event->key.keysym.sym == SDLK_t)
	//{
	//	mPlayerShip->SetCounterclockwiseRotation();
	//}
	//else if (event->key.keysym.sym == SDLK_p)
	//{
	//	mPlayerShip->StopRotate();
	//}

	//else if (event->key.keysym.sym == SDLK_p)
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
	mKeyboardHandler.HandleKeyboardEvent(event);
	
	//if (event->key.keysym.sym == SDLK_RETURN || event->key.keysym.sym == SDLK_KP_ENTER)
	//{
	//	//const std::string& mapFile = "res/maps/2.map";
	//	//mTestMap.OnLoad(mapFile, "ss_nomargin");
	//	mTestSail.IncreaseSailLevel();
	//}
	//else if (event->key.keysym.sym == SDLK_w)
	//{
	//	//mTestSail.IncreaseSailLevel();
	//	mPlayerShip->OnWKeyAction();
	//}
	//else if (event->key.keysym.sym == SDLK_s)
	//{
	//	//mTestSail.DecreaseSailLevel();
	//	mPlayerShip->OnSKeyAction();
	//}

}

void AppStateTest::OnResize(int w, int h)
{
	LOG_INFO("Window resized to {0}x{1}",w,h);
}


void AppStateTest::SetupTargetWaypoints()
{
	const int nrolls = WAYPOINTS_COUNT;

	std::random_device rd;
	std::mt19937 gen(rd());
	for (int i = 0; i < nrolls; ++i)
	{
		std::uniform_int_distribution<int> disX(0, App::GetWindowTargetWidth() * 8 / 10);
		std::uniform_int_distribution<int> disY(0, App::GetWindowTargetHeight() * 8 / 10);

		mTargetWaypoints.push_back(std::make_shared<TargetWaypoint>(disX(gen), disY(gen)));
	}


}

void AppStateTest::OnActivate(SDL_Renderer* Renderer)
{
	this->Renderer = Renderer;
	const std::string& mapFile = "res/maps/4.map";
	mTestMap.OnLoad(mapFile, "ss_nomargin");

	//mPlayerMovementController = std::make_unique<ShipWithSailsMovementController>(&mTestSail, &mVelCalc);
	mVelCalc = std::make_unique< NoAccelerationVelocityCalculator>();

	mThisShouldNotBeAUniquePtrCalc = std::make_unique< NoAccelerationVelocityCalculator>();

	/*mPlayerMovementController = std::make_unique<ShipWithEngineMovementController>(std::move(mVelCalc));
	mAIShipMovementController = std::make_unique<AIGotoTargetASAPController>(std::move(mThisShouldNotBeAUniquePtrCalc));*/
	
	mPlayerMovementController = new PlayerShipController(std::move(mVelCalc));
	mAIShipMovementController = new AIGotoTargetASAPController (std::move(mThisShouldNotBeAUniquePtrCalc));

	//mPlayerShip = std::make_shared<Ship>(std::move(mPlayerMovementController));
	mPlayerShip =  new Ship(std::move(mPlayerMovementController));

	SetupTargetWaypoints();


	/*mTargetWaypoints.push_back(std::make_shared<TargetWaypoint>(100, 600));
	mTargetWaypoints.push_back(std::make_shared<TargetWaypoint>(1200, 900));*/

	//mTargetWaypoints.push_back(std::make_shared<TargetWaypoint>(100, 100));
	//mTargetWaypoints.push_back(std::make_shared<TargetWaypoint>(1000, 400));

	TargetWaypointBrowser::GetInstance().SetLevelTargetWaypoints(mTargetWaypoints);

	//TargetWaypointBrowser::GetInstance().SetNextTargetWaypoint(mPlayerShip);

	mPlayerShip->SetTargetWaypoint();

	mAIShip = new Ship(std::move(mAIShipMovementController));


	mAIShip->SetTargetWaypoint();


	//mAITargetWaypointsDisplay.SetTargetWaypoints(TargetWaypointBrowser::GetInstance().GetCurrentTargetWaypoint(mAIShipMovementController), TargetWaypointBrowser::GetInstance().GetNextTargetWaypoint(mAIShipMovementController));

	mTargetWaypointsDisplay.SetTargetWaypoints(TargetWaypointBrowser::GetInstance().GetCurrentTargetWaypoint(mPlayerMovementController), TargetWaypointBrowser::GetInstance().GetNextTargetWaypoint(mPlayerMovementController));
	Camera::CameraControl.SetCameraWidth(1920);
	Camera::CameraControl.SetCameraHeight(1080);
	Camera::CameraControl.SetTarget(mPlayerShip->GetX(), mPlayerShip->GetY());


	int w, h = 0;
	mTestMap.GetLevelSize(w, h);
	Camera::CameraControl.SetLevelLimits(w,h);
	


	//mTargetWaypoints[3]->SetTextureAlpha(214);

	//mAIShip = std::make_unique<Ship>(std::move(mPlayerMovementController));
}

void AppStateTest::OnDeactivate()
{
	if(mPlayerShip)	delete(mPlayerShip);
	if(mAIShip) delete(mAIShip);
	if (mPlayerMovementController) delete(mPlayerMovementController);
	if (mAIShipMovementController) delete(mAIShipMovementController);
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
	if (mKeyboardHandler.IsPressed(SDLK_UP))
	{
		mPlayerShip->OnWKeyAction();
	}
	if (mKeyboardHandler.IsPressed(SDLK_DOWN))
	{
		mPlayerShip->OnSKeyAction();
	}
	if (mKeyboardHandler.IsPressed(SDLK_RIGHT))
	{
		mPlayerShip->OnDKeyAction();
	}
	if (mKeyboardHandler.IsPressed(SDLK_LEFT))
	{
		mPlayerShip->OnAKeyAction();
	}
	if (mKeyboardHandler.IsReleased(SDLK_KP_ENTER))
	{
		LOG_INFO("Enter released!");
	}
	if (mAIShip->Move() == MoveReturnValues::reachedWaypoint)
	{
		//mAITargetWaypointsDisplay.SetTargetWaypoints(TargetWaypointBrowser::GetInstance().GetCurrentTargetWaypoint(mAIShipMovementController), TargetWaypointBrowser::GetInstance().GetNextTargetWaypoint(mAIShipMovementController));
	}
	if (mPlayerShip->Move() == MoveReturnValues::reachedWaypoint)
	{
		mTargetWaypointsDisplay.SetTargetWaypoints(TargetWaypointBrowser::GetInstance().GetCurrentTargetWaypoint(mPlayerMovementController), TargetWaypointBrowser::GetInstance().GetNextTargetWaypoint(mPlayerMovementController));
	}
	mPlayerShip->Rotate();
	//mAIShip->Move();
	//mAIShipMovementController->OnLoop();
}



void AppStateTest::OnRender()
{
	//TextureBank::Get("bg_1920_1080")->RenderScaled(0, 0, App::GetInstance()->GetWindowWidth(), App::GetInstance()->GetWindowHeight(), mPlayerX/2, mPlayerY/2, TextureBank::Get("bg_1920_1080")->GetWidth()/2, TextureBank::Get("bg_1920_1080")->GetHeight()/2);

	mPlayerShip->AddToRenderQueue(1, { 255, 0, 0 });
	mTestMap.AddToRenderQueue(0, 0);

	Texture screenText;
	Texture shipDataScreenText;
	Texture waypointsProgress;
	Texture AIwaypointsProgress;

	auto& fps = FPS::GetInstance();


	const std::string& shipControllerData = mPlayerShip->ToText();
	//std::string spritesCount = std::to_string(RenderQueue::GetInstance().GetSpritesCount());
	std::string spritesCount = fps.GetFpsString();
	//screenText.LoadText(Fonts::GetInstance().GetFont(), spritesCount, SDL_Color{ 255, 255, 255 });
	screenText.LoadText(Fonts::GetInstance().GetFont(), shipControllerData, SDL_Color{ 255, 255, 255 });
	screenText.AddToRenderQueue(0, 20, screenText.GetWidth(), screenText.GetHeight(), 0, 0, screenText.GetWidth(), screenText.GetHeight(), 100, true);

	std::string cameraX = "camera X: " + std::to_string(Camera::CameraControl.GetCameraRect().x);
	std::string cameraY = "camera Y: " + std::to_string(Camera::CameraControl.GetCameraRect().y);

	std::string cameraXY = cameraX + '\n' + cameraY;

	shipDataScreenText.LoadText(Fonts::GetInstance().GetFont(), cameraXY, SDL_Color{ 255, 255, 255 });
	shipDataScreenText.AddToRenderQueue(1600, 700, shipDataScreenText.GetWidth(), shipDataScreenText.GetHeight(), 0, 0, shipDataScreenText.GetWidth(), shipDataScreenText.GetHeight(), 100, true);


	const std::string& waypointsProgressString = "Player reached " + std::to_string(TargetWaypointBrowser::GetInstance().GetReachedWaypointsCounter(mPlayerMovementController)) + "/" + std::to_string(WAYPOINTS_COUNT) + " waypoints";
	waypointsProgress.LoadText(Fonts::GetInstance().GetFont(), waypointsProgressString, SDL_Color{ 255, 255, 255 });
	waypointsProgress.AddToRenderQueue(0, 200, waypointsProgress.GetWidth(), waypointsProgress.GetHeight(), 0, 0, waypointsProgress.GetWidth(), waypointsProgress.GetHeight(), 100, true);



	const std::string& AIwaypointsProgressString = "AI reached " + std::to_string(TargetWaypointBrowser::GetInstance().GetReachedWaypointsCounter(mAIShipMovementController)) + "/" + std::to_string(WAYPOINTS_COUNT) + " waypoints";
	AIwaypointsProgress.LoadText(Fonts::GetInstance().GetFont(), AIwaypointsProgressString, SDL_Color{ 255, 0, 0 });
	AIwaypointsProgress.AddToRenderQueue(0, 400, AIwaypointsProgress.GetWidth(), AIwaypointsProgress.GetHeight(), 0, 0, AIwaypointsProgress.GetWidth(), AIwaypointsProgress.GetHeight(), 100, true);

	//for (auto&& wp : mTargetWaypoints)
	//{
	//	wp->AddToRenderQueue(5);
	//}

	//mAITargetWaypointsDisplay.AddToRenderQueue(5, true, {255, 0, 0});
	mTargetWaypointsDisplay.AddToRenderQueue(5, false, {0, 0, 255});

	mAIShip->AddToRenderQueue(1);

	RenderQueue::GetInstance().Render(Camera::CameraControl.GetCameraRect());

	//TextureBank::Get("boat")->RenderScaled(App::GetInstance()->GetWindowWidth()/2, App::GetInstance()->GetWindowHeight()/2);

	//std::string playerPosString = "mPlayerx = " + std::to_string(mPlayerX);
	//ScreenText::GetInstance().RenderText(playerPosString, 200, 200, SDL_Color{ 255, 0, 0 });

	//std::string lastMouseClickPos = std::to_string(lastMouseClick.x) + " " + std::to_string(lastMouseClick.y);
	//ScreenText::GetInstance().RenderText(lastMouseClickPos, 200, 200, SDL_Color{ 255, 255, 255 });


	//ScreenText::GetInstance().RenderText(spritesCount, 200, 200, SDL_Color{ 255, 255, 255 });


}

void AppStateTest::DebugTextRender()
{
}



AppStateTest* AppStateTest::GetInstance()
{
	return &Instance;
}