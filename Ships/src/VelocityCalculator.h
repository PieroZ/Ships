#pragma once


class VelocityCalculator
{
public:
	virtual int CalculateVelocityFromWind(int shipVelocity, int windVelocity, double sailsVelocityModifier) = 0;
};

