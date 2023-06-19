#pragma once
#include "ShipWithEngineMovementController.h"
#include "TargetWaypoint.h"


class AIGotoTargetASAPController : public ShipWithEngineMovementController
{
public:
	AIGotoTargetASAPController(std::unique_ptr<VelocityCalculator> velocityCalculator);
	~AIGotoTargetASAPController() = default;
	virtual void OnLoop() override;
	//void SetTargetWaypoint(std::shared_ptr<TargetWaypoint> targetWaypoint);
private:
	void RotateToNextTarget();
	double CalculateAngle(double x1, double y1, double x2, double y2) const;
};

