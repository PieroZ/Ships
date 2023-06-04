#include "ShipWithSailsMovementController.h"
#include "Wind.h"
#include "Log.h"

ShipWithSailsMovementController::ShipWithSailsMovementController(SailsController* sailsController, VelocityCalculator* velocityCalculator) : mSailsController(sailsController), mVelocityCalculator(velocityCalculator)
{

}

ShipWithSailsMovementController::~ShipWithSailsMovementController()
{
	printf("Memory of ShipWithSailsMovementController has been freed!\n");
}

double ShipWithSailsMovementController::GetSailsVelocityModifier(SailLevel level)
{
	switch (level)
	{
		case off:
			return 0.0;
		case half:
			return 0.5;
		case full:
			return 1.0;
		default:
			return 0.0;
	}
}

void ShipWithSailsMovementController::Move()
{
	CalculateSpeed();

	mX += mVelocityX;
}

void ShipWithSailsMovementController::CalculateSpeed()
{
	auto sailsLevel = mSailsController->GetSailLevel();
	auto wind = Wind::GetWindInstance();

	auto sailsVelocityMoidifer = GetSailsVelocityModifier(sailsLevel);

	auto xVelocity = mVelocityCalculator->CalculateVelocityFromWind(mVelocityX, wind.GetWindVelocity(), sailsVelocityMoidifer);
	mVelocityX = xVelocity;
}
