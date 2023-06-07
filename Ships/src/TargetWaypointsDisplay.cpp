#include "TargetWaypointsDisplay.h"

void TargetWaypointsDisplay::SetTargetWaypoints(std::shared_ptr<TargetWaypoint> current, std::shared_ptr<TargetWaypoint> next)
{
	//current->SetTextureAlpha(255);
	//next->SetTextureAlpha(255);


	if (current)
	{
		mCurrentTarget = current;
		mCurrentTarget->SetDefaultTexture();
	}
	if (next)
	{
		mNextTarget = next;
		mNextTarget->SetSecondaryTexture();
		mNextTarget->SetTextureAlpha(NEXT_TARGET_ALPHA);
	}

	//mCurrentTarget->SetTextureAlpha(NEXT_TARGET_ALPHA);
}

void TargetWaypointsDisplay::AddToRenderQueue(int renderOrder)
{
	if (mCurrentTarget)
	{
		mCurrentTarget->AddToRenderQueue(renderOrder);
	}

	if (mNextTarget)
	{
		mNextTarget->AddToRenderQueue(renderOrder);
	}
}
