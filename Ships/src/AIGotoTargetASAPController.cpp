#include "AIGotoTargetASAPController.h"
#include "Log.h"
#include <cmath>

AIGotoTargetASAPController::AIGotoTargetASAPController(std::unique_ptr<VelocityCalculator> velocityCalculator) : ShipWithEngineMovementController(std::move(velocityCalculator))
{
}

void AIGotoTargetASAPController::OnLoop()
{
    if (!mCurrentTargetWaypoint) return;

    //OnWKeyAction();
    double angle = (CalculateAngle(mX, mY, mCurrentTargetWaypoint->GetCollisionCenter().x, mCurrentTargetWaypoint->GetCollisionCenter().y));
    double desiredShipAngle = (270.0 - angle);


    if (desiredShipAngle >= 360.0)
	{
		desiredShipAngle -= 360.0;
	}

   // LOG_INFO("desiredShipAngle = {0} ",desiredShipAngle);
    
    //if (angle < 90.0)
    //{
    //    desiredShipAngle += 90.0;
    //}

    bool isFasterToRotateClockwise = (std::abs(mShipRotation - desiredShipAngle) < 180.0) ? true : false;

    if (std::abs(mShipRotation - desiredShipAngle) >= 5.0)
    {
        RotateShipClockwise();
    }

    /*if (isFasterToRotateClockwise)
    {
        RotateShipClockwise();
    }
    else
    {
        RotateShipCounterclockwise();
    }*/

    // counterclockwise angle calculation
    // dla 32,31 kat lodki to 270-32
    //  dla 90 kat lodki to 0
    // dla 145 kat lodki to 45
    //LOG_INFO(angle);
    //LOG_INFO(shipAngle);
    //mShipRotation 
}

void AIGotoTargetASAPController::RotateToNextTarget()
{

}

// 0 Angle corresponds to ship headed towards the x axis
double AIGotoTargetASAPController::CalculateAngle(double x1, double y1, double x2, double y2) const
{
    double deltaX = x2 - x1;
    double deltaY = y1 - y2;

    double angleInRadians = std::atan2(deltaY, deltaX);
    double angleInDegrees = angleInRadians * 180.0 / M_PI;

    return angleInDegrees;
}
