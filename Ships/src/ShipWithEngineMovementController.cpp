#include "ShipWithEngineMovementController.h"

#include "Colideable.h"
#include "TargetWaypointBrowser.h"

ShipWithEngineMovementController::ShipWithEngineMovementController(std::unique_ptr<VelocityCalculator> velocityCalculator) : mVelocityCalculator(std::move(velocityCalculator))
{
}

ShipWithEngineMovementController::~ShipWithEngineMovementController()
{
}

void ShipWithEngineMovementController::ModifyEngineSpeed(double deltaSpeed)
{
	mEngineSpeed += deltaSpeed;
}

int ShipWithEngineMovementController::Move(double & deltaX, double & deltaY)
{
	CalculateSpeed();

	mX += mVelocityX;
	mY += mVelocityY;

	deltaX = mVelocityX;
	deltaY = mVelocityY;


	if (mCurrentTargetWaypoint)
	{
		SDL_Rect a = mCurrentTargetWaypoint->GetCollisionRect();
		SDL_Rect b{ static_cast<int>(*GetX()), static_cast<int>(*GetY()) ,mShipTextureWidth, mShipTextureHeight};
		bool reachedTargetWaypoint = Colideable::CheckBoxCollision(a, b);

		if (reachedTargetWaypoint)
		{
			mCurrentTargetWaypoint = TargetWaypointBrowser::GetInstance().GetNextTargetWaypoint(this);
			TargetWaypointBrowser::GetInstance().SetNextTargetWaypoint(this);
			return reachedWaypoint;
		}
	}
	return movedOK;
}


void ShipWithEngineMovementController::SetTargetWaypoint()
{
	TargetWaypointBrowser::GetInstance().SetNextTargetWaypoint(this);
	mCurrentTargetWaypoint = TargetWaypointBrowser::GetInstance().GetCurrentTargetWaypoint(this);
}

void ShipWithEngineMovementController::CalculateSpeed()
{
	mVelocityCalculator->CalculateVelocityFromEngine(mEngineSpeed, mShipRotation, mVelocityX, mVelocityY);
}

void ShipWithEngineMovementController::OnWKeyAction()
{
	ModifyEngineSpeed(ENGINE_ACC);
}

void ShipWithEngineMovementController::OnSKeyAction()
{
	ModifyEngineSpeed(-ENGINE_ACC);
}
