#pragma once
#include "AbstractShipMovementController.h"
#include "SailsController.h"
#include "VelocityCalculator.h"

class ShipWithSailsMovementController : public AbstractShipMovementController
{
private:
	SailsController* mSailsController;
	VelocityCalculator* mVelocityCalculator;
	
public:
	ShipWithSailsMovementController(SailsController* sailsController, VelocityCalculator* velocityCalculator);
	~ShipWithSailsMovementController();
	double GetSailsVelocityModifier(SailLevel level);


	// Inherited via AbstractShipMovementController
	virtual void Move() override;
private:
	virtual void CalculateSpeed() override;
};

