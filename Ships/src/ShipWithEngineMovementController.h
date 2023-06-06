#pragma once

#include "AbstractShipMovementController.h"
#include "VelocityCalculator.h"

#include <memory>

class ShipWithEngineMovementController : public AbstractShipMovementController
{
private:
	std::unique_ptr<VelocityCalculator> mVelocityCalculator;
	double mEngineSpeed = 1.0;
	inline static const double ENGINE_ACC = 0.1;
public:

	ShipWithEngineMovementController(std::unique_ptr<VelocityCalculator> velocityCalculator);
	~ShipWithEngineMovementController();


	void ModifyEngineSpeed(double deltaSpeed);


	// Inherited via AbstractShipMovementController
	virtual void OnWKeyAction() override;
	virtual void OnSKeyAction() override;
	virtual void Move() override;
private:
	virtual void CalculateSpeed() override;
};
