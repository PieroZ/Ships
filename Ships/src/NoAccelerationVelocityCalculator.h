#pragma once

#include "VelocityCalculator.h"

class NoAccelerationVelocityCalculator : public VelocityCalculator
{
public:
	// Inherited via VelocityCalculator
	~NoAccelerationVelocityCalculator();
	virtual int CalculateVelocityFromWind(int shipVelocity, int windVelocity, double sailsVelocityModifier) override;
	virtual void CalculateVelocityFromEngine(double engineSpeed, const int shipAngle, double& velX, double& velY) override;
};

