#pragma once
#include "ShipMovementInterface.h"
#include "SailsController.h"
#include "VelocityCalculator.h"

class ShipWithSailsMovementController : public ShipMovementInterface
{
private:
	SailsController* mSailsController;
	VelocityCalculator* mVelocityCalculator;
	//inline static const double ROTATION_SPEED = 0.4;
	
public:
	ShipWithSailsMovementController(SailsController* sailsController, VelocityCalculator* velocityCalculator);
	~ShipWithSailsMovementController();
	double GetSailsVelocityModifier(SailLevel level);


	// Inherited via ShipMovementInterface
	virtual void OnWKeyAction() override;
	virtual void OnSKeyAction() override;
	virtual int Move(double& deltaX, double& deltaY) override;
	/*virtual void RotateShipClockwise() override;
	virtual void RotateShipCounterclockwise() override;*/
private:
	virtual void CalculateSpeed() override;

};

