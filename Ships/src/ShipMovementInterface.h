#pragma once
#include <SDL.h>
#include <string>


enum MoveReturnValues
{
	movedOK,
	reachedWaypoint
};


class ShipMovementInterface
{
public:
	virtual ~ShipMovementInterface();
	virtual int Move(double& deltaX, double& deltaY) = 0;
	virtual void CalculateSpeed() = 0;
	virtual void OnWKeyAction() = 0;
	virtual void OnSKeyAction() = 0;

	virtual void OnLoop();

	virtual void RotateShipClockwise();
	virtual void RotateShipCounterclockwise();


	virtual std::string ToText();
	void SetTextureCenter(const SDL_Point& center);
	void SetTextureSize(int width, int height);

	double* GetX() ;
	double* GetY() ;
	double GetVelocityX() const;
	double GetVelocityY() const;
	double GetShipRotation() const;
	const SDL_Point& GetTextureCenter() const;


protected:
	double mX = 400.0;
	double mY = 400.0;
	int mShipTextureWidth = 0;
	int mShipTextureHeight = 0;
	double mVelocityX = 0.0;
	double mVelocityY = 0.0;
	double mShipRotation = 0.0;
	SDL_Point mTextureCenter;



	inline static const double ROTATION_SPEED = 2.4;
};

