#pragma once
#include "Texture.h"
#include "Renderable.h"
#include <string>

class TargetWaypoint : public Renderable
{
private:
	inline static const std::string TARGET_WAYPOINT_TEXTURE_NAME = "dot";
	inline static const std::string TARGET_WAYPOINT_TEXTURE_CLONE_NAME = "dot2";
public:
	TargetWaypoint(int x, int y);
	~TargetWaypoint() = default;
	void SetTextureAlpha(Uint8 alpha);
	void SetDefaultTexture();
	void SetSecondaryTexture();
	SDL_Rect GetCollisionRect() const;
	SDL_Point GetCollisionCenter() const;
	virtual void AddToRenderQueue(int renderOrder) override;

};

