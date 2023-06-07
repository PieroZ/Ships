#include "AbstractShipMovementController.h"
#include <sstream>

AbstractShipMovementController::~AbstractShipMovementController()
{

}

void AbstractShipMovementController::OnLoop()
{
}

void AbstractShipMovementController::RotateShipClockwise()
{
	mShipRotation += ROTATION_SPEED;
}

void AbstractShipMovementController::RotateShipCounterclockwise()
{
	mShipRotation -= ROTATION_SPEED;
}

std::string AbstractShipMovementController::ToText()
{
	std::stringstream ss;
	ss << "mX " << mX                      << '\n';
	ss << "mY " << mY                      << '\n';
	ss << "mVelocityX " << mVelocityX      << '\n';
	ss << "mVelocityY " << mVelocityY      << '\n';
	ss << "mShipRotation " << mShipRotation << '\n';

	return ss.str();
}

void AbstractShipMovementController::SetTextureCenter(const SDL_Point& center)
{
	mTextureCenter = center;
}

double AbstractShipMovementController::GetX() const
{
	return mX;
}

double AbstractShipMovementController::GetY() const
{
	return mY;
}

double AbstractShipMovementController::GetVelocityX() const
{
	return mVelocityX;
}

double AbstractShipMovementController::GetVelocityY() const
{
	return mVelocityY;
}

double AbstractShipMovementController::GetShipRotation() const
{
	return mShipRotation;
}

const SDL_Point& AbstractShipMovementController::GetTextureCenter() const
{
	return mTextureCenter;
}
