#include "ShipMovementInterface.h"
#include <sstream>

ShipMovementInterface::~ShipMovementInterface()
{

}

void ShipMovementInterface::OnLoop()
{
}

void ShipMovementInterface::RotateShipClockwise()
{
	mShipRotation += ROTATION_SPEED;
	if (mShipRotation >= 360.0)
	{
		mShipRotation -= 360.0;
	}
}

void ShipMovementInterface::RotateShipCounterclockwise()
{
	mShipRotation -= ROTATION_SPEED;
	if (mShipRotation <= 0.0)
	{
		mShipRotation += 360.0;
	}
}

std::string ShipMovementInterface::ToText()
{
	std::stringstream ss;
	ss << "mX " << mX                      << '\n';
	ss << "mY " << mY                      << '\n';
	ss << "mVelocityX " << mVelocityX      << '\n';
	ss << "mVelocityY " << mVelocityY      << '\n';
	ss << "mShipRotation " << mShipRotation << '\n';

	return ss.str();
}

void ShipMovementInterface::SetTextureCenter(const SDL_Point& center)
{
	mTextureCenter = center;
}

void ShipMovementInterface::SetTextureSize(int width, int height)
{
	mShipTextureWidth = width;
	mShipTextureHeight = height;
}

double* ShipMovementInterface::GetX() 
{
	return &mX;
}

double* ShipMovementInterface::GetY() 
{
	return &mY;
}

double ShipMovementInterface::GetVelocityX() const
{
	return mVelocityX;
}

double ShipMovementInterface::GetVelocityY() const
{
	return mVelocityY;
}

double ShipMovementInterface::GetShipRotation() const
{
	return mShipRotation;
}

const SDL_Point& ShipMovementInterface::GetTextureCenter() const
{
	return mTextureCenter;
}
