#pragma once

#include "VelocityCalculator.h"

class NoAccelerationVelocityCalculator : public VelocityCalculator
{
public:
	// Inherited via VelocityCalculator
	virtual int CalculateVelocityFromWind(int shipVelocity, int windVelocity, double sailsVelocityModifier) override;
};

