#include "NoAccelerationVelocityCalculator.h"
#include <cmath>

NoAccelerationVelocityCalculator::~NoAccelerationVelocityCalculator()
{
}

int NoAccelerationVelocityCalculator::CalculateVelocityFromWind(int shipVelocity, int windVelocity, double sailsVelocityModifier)
{
	int resultVelocity = static_cast<int>(windVelocity * sailsVelocityModifier);

	return resultVelocity;
}

// This function assumes that the ship's sprite prow is directed at the bottom - alongside the y axis hence the formula
void NoAccelerationVelocityCalculator::CalculateVelocityFromEngine(double engineSpeed, const int shipAngle, double& velX, double& velY)
{
	static const double PI = 3.14159265;
	velX = -1.0 * sin(shipAngle * PI/180) * engineSpeed;
	velY =  1.0 * cos(shipAngle * PI/180) * engineSpeed;
}
