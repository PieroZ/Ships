#include "TargetWaypointBrowser.h"
#include "Log.h"

TargetWaypointBrowser& TargetWaypointBrowser::GetInstance()
{
	static TargetWaypointBrowser instance;
	return instance;
}

void TargetWaypointBrowser::SetNextTargetWaypoint(ShipMovementInterface* ship)
{
	if (mLevelTargetWaypoints.size() <= 0)
	{
		LOG_ERROR("Cannot set the next target waypoint because mLevelTargetWaypoints.size() <= 0 !");
	}

	// Check if ship already in map
	if (mCurrentWaypointTargetMap.count(ship))
	{
		std::shared_ptr<TargetWaypoint> nextTargetWaypoint;
		auto currentTarget = GetCurrentTargetWaypoint(ship);

		auto it = find(mLevelTargetWaypoints.begin(), mLevelTargetWaypoints.end(), currentTarget);

		// If element was found
		if (it != mLevelTargetWaypoints.end())
		{
			int index = it - mLevelTargetWaypoints.begin();
			if (index + 1 < mLevelTargetWaypoints.size())
			{
				nextTargetWaypoint = mLevelTargetWaypoints[index + 1];
			}

			mCurrentWaypointTargetMap[ship] = nextTargetWaypoint;
		}
		//Increase reached waypoints counter
		mReachedWaypointsCounter[ship]++;
	}
	// If it's not already in the map set the target to first waypoint
	else
	{
		mCurrentWaypointTargetMap[ship] = mLevelTargetWaypoints[0];
		mReachedWaypointsCounter[ship] = 0;
	}
}

Uint16 TargetWaypointBrowser::GetReachedWaypointsCounter(ShipMovementInterface* ship) const
{
	return mReachedWaypointsCounter.at(ship);
}

void TargetWaypointBrowser::SetLevelTargetWaypoints(std::vector<std::shared_ptr<TargetWaypoint>>& waypoints)
{
	mLevelTargetWaypoints = waypoints;
}

std::shared_ptr<TargetWaypoint> TargetWaypointBrowser::GetCurrentTargetWaypoint(ShipMovementInterface* ship) const
{
	return mCurrentWaypointTargetMap.at(ship);
}

std::shared_ptr<TargetWaypoint> TargetWaypointBrowser::GetNextTargetWaypoint(ShipMovementInterface* ship) const
{
	std::shared_ptr<TargetWaypoint> nextTargetWaypoint;
	auto currentTarget = GetCurrentTargetWaypoint(ship);

	auto it = find(mLevelTargetWaypoints.begin(), mLevelTargetWaypoints.end(), currentTarget);

	// If element was found
	if (it != mLevelTargetWaypoints.end())
	{
		int index = it - mLevelTargetWaypoints.begin();
		if (index + 1 < mLevelTargetWaypoints.size())
		{
			nextTargetWaypoint = mLevelTargetWaypoints[index + 1];
		}
	}
	else
	{
		LOG_ERROR("Did not find the next target waypoint !");
	}


	return nextTargetWaypoint;
}
