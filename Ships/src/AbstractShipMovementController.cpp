#include "AbstractShipMovementController.h"

AbstractShipMovementController::~AbstractShipMovementController()
{

}

int AbstractShipMovementController::GetX() const
{
	return mX;
}

int AbstractShipMovementController::GetY() const
{
	return mY;
}

int AbstractShipMovementController::GetVelocityX() const
{
	return mVelocityX;
}

int AbstractShipMovementController::GetVelocityY() const
{
	return mVelocityY;
}
