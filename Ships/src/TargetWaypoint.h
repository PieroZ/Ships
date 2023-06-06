#pragma once
#include "Texture.h"
#include "Renderable.h"
#include <string>

class TargetWaypoint : public Renderable
{
private:
	inline static const std::string TARGET_WAYPOINT_TEXTURE_NAME = "dot";
public:
	TargetWaypoint(int x, int y);
	void SetTextureAlpha(Uint8 alpha);
	virtual void AddToRenderQueue(int renderOrder) override;

};

