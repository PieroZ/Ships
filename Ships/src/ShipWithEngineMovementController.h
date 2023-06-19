#pragma once

#include "ShipMovementInterface.h"
#include "VelocityCalculator.h"
#include "TargetWaypoint.h"

#include <memory>

class ShipWithEngineMovementController : public ShipMovementInterface
{
protected:
	std::unique_ptr<VelocityCalculator> mVelocityCalculator;
	std::shared_ptr<TargetWaypoint> mCurrentTargetWaypoint;
	double mEngineSpeed = 5.0;
	inline static const double ENGINE_ACC = 0.1;

public:

	ShipWithEngineMovementController(std::unique_ptr<VelocityCalculator> velocityCalculator);
	~ShipWithEngineMovementController();


	void ModifyEngineSpeed(double deltaSpeed);


	// Inherited via ShipMovementInterface
	virtual void OnWKeyAction() override;
	virtual void OnSKeyAction() override;
	virtual int Move(double & deltaX, double & deltaY) override;
	void SetTargetWaypoint();
private:
	virtual void CalculateSpeed() override;
};
