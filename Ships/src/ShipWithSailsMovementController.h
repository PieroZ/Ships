#pragma once
#include "AbstractShipMovementController.h"
#include "SailsController.h"
#include "VelocityCalculator.h"

class ShipWithSailsMovementController : public AbstractShipMovementController
{
private:
	SailsController* mSailsController;
	VelocityCalculator* mVelocityCalculator;
	//inline static const double ROTATION_SPEED = 0.4;
	
public:
	ShipWithSailsMovementController(SailsController* sailsController, VelocityCalculator* velocityCalculator);
	~ShipWithSailsMovementController();
	double GetSailsVelocityModifier(SailLevel level);


	// Inherited via AbstractShipMovementController
	virtual void OnWKeyAction() override;
	virtual void OnSKeyAction() override;
	virtual void Move() override;
	/*virtual void RotateShipClockwise() override;
	virtual void RotateShipCounterclockwise() override;*/
private:
	virtual void CalculateSpeed() override;

};

