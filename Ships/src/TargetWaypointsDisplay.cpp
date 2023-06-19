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

void TargetWaypointsDisplay::AddToRenderQueue(int renderOrder, bool drawRectFlag /*= false*/, SDL_Color c)
{
	if (mCurrentTarget)
	{
		mCurrentTarget->AddToRenderQueue(renderOrder, drawRectFlag, c);
	}

	if (mNextTarget)
	{
		mNextTarget->AddToRenderQueue(renderOrder, drawRectFlag, c);
	}
}
