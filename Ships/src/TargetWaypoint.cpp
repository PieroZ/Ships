#include "TargetWaypoint.h"
#include "TextureBank.h"

TargetWaypoint::TargetWaypoint(int x, int y) : Renderable(x, y)
{
	auto&& texture = TextureBank::Get(TARGET_WAYPOINT_TEXTURE_NAME);
	SetTexture(texture);
}

void TargetWaypoint::SetTextureAlpha(Uint8 alpha)
{
	mAlpha = alpha;
}

void TargetWaypoint::AddToRenderQueue(int renderOrder)
{
	Renderable::AddToRenderQueue(renderOrder);
}
