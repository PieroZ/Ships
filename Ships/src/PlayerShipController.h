#pragma once

#include "ShipWithEngineMovementController.h"

class PlayerShipController : public ShipWithEngineMovementController
{
public:
	PlayerShipController(std::unique_ptr<VelocityCalculator> velocityCalculator);
	virtual int Move(double& deltaX, double& deltaY) override;
};

