#include "NoAccelerationVelocityCalculator.h"

int NoAccelerationVelocityCalculator::CalculateVelocityFromWind(int shipVelocity, int windVelocity, double sailsVelocityModifier)
{
	int resultVelocity = static_cast<int>(windVelocity * sailsVelocityModifier);

	return resultVelocity;
}
