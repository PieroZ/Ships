#pragma once


class VelocityCalculator
{
public:
	virtual int CalculateVelocityFromWind(int shipVelocity, int windVelocity, double sailsVelocityModifier) = 0;
	virtual void CalculateVelocityFromEngine(double engineSpeed, const int shipAngle, double& velX, double& velY);
};

