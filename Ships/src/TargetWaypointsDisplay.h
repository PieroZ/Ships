#pragma once
#include <memory>
#include "TargetWaypoint.h"
#include "Renderable.h"


class TargetWaypointsDisplay : public Renderable
{
public:
	void SetTargetWaypoints(std::shared_ptr<TargetWaypoint> current, std::shared_ptr<TargetWaypoint> next);
	TargetWaypointsDisplay() = default;
	~TargetWaypointsDisplay() = default;
private:
	std::shared_ptr<TargetWaypoint> mCurrentTarget;
	std::shared_ptr<TargetWaypoint> mNextTarget;

	static const Uint8 NEXT_TARGET_ALPHA = 127;

public:
	virtual void AddToRenderQueue(int renderOrder, bool drawRectFlag = false, SDL_Color c = {0,0,0}) override;
};