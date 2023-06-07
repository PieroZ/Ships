#include "AIGotoTargetASAPController.h"
#include "Log.h"
#include <cmath>

AIGotoTargetASAPController::AIGotoTargetASAPController(std::unique_ptr<VelocityCalculator> velocityCalculator) : ShipWithEngineMovementController(std::move(velocityCalculator))
{
}

void AIGotoTargetASAPController::OnLoop()
{
    LOG_INFO(CalculateAngle(mX, mY, 400.0, 200.0));
}

void AIGotoTargetASAPController::RotateToNextTarget()
{

}

double AIGotoTargetASAPController::CalculateAngle(double x1, double y1, double x2, double y2) const
{
    double deltaX = x2 - x1;
    double deltaY = y2 - y1;

    double angleInRadians = std::atan2(deltaY, deltaX);
    double angleInDegrees = angleInRadians * 180.0 / M_PI;

    return angleInDegrees;
}
