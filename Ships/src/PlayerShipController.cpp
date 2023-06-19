#include "PlayerShipController.h"
#include "Camera.h"

PlayerShipController::PlayerShipController(std::unique_ptr<VelocityCalculator> velocityCalculator) : ShipWithEngineMovementController(std::move(velocityCalculator))
{
}

int PlayerShipController::Move(double& deltaX, double& deltaY)
{
    int moveStatus = ShipWithEngineMovementController::Move(deltaX, deltaY);
    Camera::CameraControl.OnMove(deltaX, deltaY);
    
    return moveStatus;
}
