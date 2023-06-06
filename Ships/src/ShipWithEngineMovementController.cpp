#include "ShipWithEngineMovementController.h"

ShipWithEngineMovementController::ShipWithEngineMovementController(std::unique_ptr<VelocityCalculator> velocityCalculator) : mVelocityCalculator(std::move(velocityCalculator))
{
}

ShipWithEngineMovementController::~ShipWithEngineMovementController()
{
}

void ShipWithEngineMovementController::ModifyEngineSpeed(double deltaSpeed)
{
	mEngineSpeed += deltaSpeed;
}

void ShipWithEngineMovementController::Move()
{
	CalculateSpeed();

	mX += mVelocityX;
	mY += mVelocityY;
}

void ShipWithEngineMovementController::CalculateSpeed()
{
	mVelocityCalculator->CalculateVelocityFromEngine(mEngineSpeed, mShipRotation, mVelocityX, mVelocityY);
}

void ShipWithEngineMovementController::OnWKeyAction()
{
	ModifyEngineSpeed(ENGINE_ACC);
}

void ShipWithEngineMovementController::OnSKeyAction()
{
	ModifyEngineSpeed(-ENGINE_ACC);
}
