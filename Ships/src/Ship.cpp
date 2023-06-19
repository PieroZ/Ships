#include "Ship.h"
#include "TextureBank.h"
#include "Log.h"
#include "RenderQueue.h"
#include "TargetWaypointBrowser.h"

//Ship::Ship(std::unique_ptr<ShipWithEngineMovementController> mPlayerMovementController) : mPlayerMovementController(std::move(mPlayerMovementController))
Ship::Ship(ShipWithEngineMovementController* mPlayerMovementController) : mPlayerMovementController(mPlayerMovementController)
{
	Init();
}

Ship::~Ship()
{
	printf("Ship has been freed!\n");
}

void Ship::AddToRenderQueue(int renderOrder, SDL_Color c )
{
	SDL_Rect srcRect;

	SDL_Rect dstRect;

	if (mAnimation)
	{
		srcRect = mAnimation->GetSrcRect();
		dstRect = mAnimation->GetSrcRect();
		dstRect.x = *mPlayerMovementController->GetX();
		dstRect.y = *mPlayerMovementController->GetY();
	}
	else
	{
		dstRect = { static_cast<int>(*mPlayerMovementController->GetX()), static_cast<int>(*mPlayerMovementController->GetY()), TextureBank::Get(mShipTextureName)->GetWidth(),TextureBank::Get(mShipTextureName)->GetHeight() };

		srcRect = TextureBank::Get(mShipTextureName)->GetEntireTextureRect();
	}
	//RenderQueue::GetInstance().AddToRenderQueue(TextureBank::Get(mShipTextureName), TextureBank::Get(mShipTextureName)->GetEntireTextureRect(), dstRect, renderOrder);
	RenderQueue::GetInstance().AddToRenderQueue(TextureBank::Get(mShipTextureName), srcRect, dstRect, mPlayerMovementController->GetShipRotation(), mPlayerMovementController->GetTextureCenter(), renderOrder, false, c);
}

bool Ship::Init()
{
	auto&& texture = TextureBank::Get(mShipTextureName);
	mPlayerMovementController->SetTextureCenter(texture->GetCenterPointOfTexture());
	mPlayerMovementController->SetTextureSize(TextureBank::Get(mShipTextureName)->GetWidth(), TextureBank::Get(mShipTextureName)->GetHeight());
	mAnimation = std::make_unique<AnimatedTexture>();
	mAnimation->InitAnimTexture(68, 68, 1, 10000);
	mAnimation->SetSpriteXY(0, 0);

	
	return LoadTexture();
}

bool Ship::LoadTexture()
{
	//Texture* texture = TextureBank::Get(mShipTextureName);
	//if (!texture)
	//{
	//    LOG_ERROR("Failed to load ship texture");
	//    return false;
	//}

	//mShipTexture = texture;
	return true;
}

int Ship::Move()
{
	mPlayerMovementController->OnLoop();
	mAnimation->OnAnimate();
	double xDelta = 0.0, yDelta = 0.0;
	return mPlayerMovementController->Move(xDelta, yDelta);

	/*if (mCurrentTargetWaypoint)
	{
		SDL_Rect a = mCurrentTargetWaypoint->GetCollisionRect();
		SDL_Rect b{ static_cast<int>(mPlayerMovementController->GetX()), static_cast<int>(mPlayerMovementController->GetY()) ,TextureBank::Get(mShipTextureName)->GetWidth(), TextureBank::Get(mShipTextureName)->GetHeight() };
		bool reachedTargetWaypoint = Colideable::CheckBoxCollision(a, b);

		if (reachedTargetWaypoint)
		{
			mCurrentTargetWaypoint = TargetWaypointBrowser::GetInstance().GetNextTargetWaypoint(this);
			TargetWaypointBrowser::GetInstance().SetNextTargetWaypoint(this);
			return reachedWaypoint;
		}
	}*/
}

void Ship::SetClockwiseRotation()
{
	if (mShipRotation == ShipRotation::clockwise)
	{
		mShipRotation = ShipRotation::none;
	}
	else
	{
		mShipRotation = ShipRotation::counterclockwise;
	}
}

void Ship::SetCounterclockwiseRotation()
{
	if (mShipRotation == ShipRotation::counterclockwise)
	{
		mShipRotation = ShipRotation::none;
	}
	else
	{
		mShipRotation = ShipRotation::clockwise;
	}
}

void Ship::SetTargetWaypoint()
{
	mPlayerMovementController->SetTargetWaypoint();
}

void Ship::StopRotate()
{
	mShipRotation = ShipRotation::none;
}

void Ship::Rotate()
{
	switch (mShipRotation)
	{
		case none:
			break;
		case clockwise:
			mPlayerMovementController->RotateShipClockwise();
			break;
		case counterclockwise:
			mPlayerMovementController->RotateShipCounterclockwise();
			break;
		default:
			break;
	}
}

double* Ship::GetX() 
{
	return mPlayerMovementController->GetX();
}

double* Ship::GetY()
{
	return mPlayerMovementController->GetY();
}
void Ship::OnWKeyAction()
{
	mPlayerMovementController->OnWKeyAction();
}

void Ship::OnDKeyAction()
{
	mPlayerMovementController->RotateShipClockwise();
}

void Ship::OnSKeyAction()
{

	mPlayerMovementController->OnSKeyAction();
}

void Ship::OnAKeyAction()
{
	mPlayerMovementController->RotateShipCounterclockwise();
}

std::string Ship::ToText()
{
	return mPlayerMovementController->ToText();
}
