#pragma once
#include <SDL.h>
#include <string>

class AbstractShipMovementController
{
public:
	virtual ~AbstractShipMovementController();
	virtual void Move() = 0;
	virtual void CalculateSpeed() = 0;
	virtual void OnWKeyAction() = 0;
	virtual void OnSKeyAction() = 0;

	virtual void RotateShipClockwise();
	virtual void RotateShipCounterclockwise();
	virtual std::string ToText();
	void SetTextureCenter(const SDL_Point& center);

	double GetX() const;
	double GetY() const;
	double GetVelocityX() const;
	double GetVelocityY() const;
	double GetShipRotation() const;
	const SDL_Point& GetTextureCenter() const;


protected:
	double mX = 400.0;
	double mY = 400.0;
	double mVelocityX = 0.0;
	double mVelocityY = 0.0;
	double mShipRotation = 0.0;
	SDL_Point mTextureCenter;

	inline static const double ROTATION_SPEED = 0.4;
};

