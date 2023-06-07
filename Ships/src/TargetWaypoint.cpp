#include "TargetWaypoint.h"
#include "TextureBank.h"

TargetWaypoint::TargetWaypoint(int x, int y) : Renderable(x, y)
{
	auto&& texture = TextureBank::Get(TARGET_WAYPOINT_TEXTURE_NAME);
	SetTexture(texture);
}

void TargetWaypoint::SetTextureAlpha(Uint8 alpha)
{
	mTexture->SetAlpha(alpha);
}

void TargetWaypoint::SetDefaultTexture()
{
	auto&& texture = TextureBank::Get(TARGET_WAYPOINT_TEXTURE_NAME);
	SetTexture(texture);
}

void TargetWaypoint::SetSecondaryTexture()
{
	auto&& texture = TextureBank::Get(TARGET_WAYPOINT_TEXTURE_CLONE_NAME);
	SetTexture(texture);
}

SDL_Rect TargetWaypoint::GetCollisionRect() const
{
	// For now we assume the collision size is equal to the texture's width and hight
	return SDL_Rect{ mX, mY, mTexture->GetWidth(), mTexture->GetHeight() };
}

void TargetWaypoint::AddToRenderQueue(int renderOrder)
{
	Renderable::AddToRenderQueue(renderOrder);
}
