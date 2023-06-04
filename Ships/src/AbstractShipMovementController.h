#pragma once
class AbstractShipMovementController
{
public:
	virtual ~AbstractShipMovementController();
	virtual void Move() = 0;
	virtual void CalculateSpeed() = 0;
	int GetX() const;
	int GetY() const;
	int GetVelocityX() const;
	int GetVelocityY() const;

protected:
	int mX = 0;
	int mY = 0;
	int mVelocityX = 0;
	int mVelocityY = 0;
};

