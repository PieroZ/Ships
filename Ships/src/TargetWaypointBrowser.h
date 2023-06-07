#pragma once
#include <unordered_map>
#include <memory>
#include <vector>

#include "Ship.h"
#include "TargetWaypoint.h"


class TargetWaypointBrowser
{
private:
	std::unordered_map<Ship*, std::shared_ptr< TargetWaypoint>> mCurrentWaypointTargetMap;
	// Waypoints are stored in order they should be reached
	std::vector<std::shared_ptr< TargetWaypoint>> mLevelTargetWaypoints;


public:
	static TargetWaypointBrowser& GetInstance();

	void SetLevelTargetWaypoints(std::vector<std::shared_ptr< TargetWaypoint>>& waypoints);
	// Below should be called whenever ship reached it's target
	void SetNextTargetWaypoint(Ship* ship);
	std::shared_ptr<TargetWaypoint> GetCurrentTargetWaypoint(Ship* ship) const;
	std::shared_ptr<TargetWaypoint> GetNextTargetWaypoint(Ship* ship) const;
private:
	TargetWaypointBrowser() = default;
	~TargetWaypointBrowser() = default;
};


//
//class TargetWaypointBrowser
//{
//private:
//	std::unordered_map<Ship*, std::shared_ptr< TargetWaypoint>> mCurrentWaypointTargetMap;
//	// Waypoints are stored in order they should be reached
//	std::vector<std::shared_ptr< TargetWaypoint>> mLevelTargetWaypoints;
//
//
//public:
//	static TargetWaypointBrowser& GetInstance();
//
//	void SetLevelTargetWaypoints(std::vector<std::shared_ptr< TargetWaypoint>>& waypoints);
//	// Below should be called whenever ship reached it's target
//	void SetNextTargetWaypoint(Ship* ship);
//	std::shared_ptr<TargetWaypoint> GetCurrentTargetWaypoint(Ship* ship) const;
//	std::shared_ptr<TargetWaypoint> GetNextTargetWaypoint(Ship* ship) const;
//private:
//	TargetWaypointBrowser() = default;
//	~TargetWaypointBrowser() = default;
//};
//
