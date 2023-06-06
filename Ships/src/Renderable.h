#pragma once
#include "Texture.h"

class Renderable
{
public:
	Renderable(int x, int y);
	virtual ~Renderable() = default;
	
	void SetTexture(Texture* texture);
	virtual void AddToRenderQueue(int renderOrder);

protected:
	int mX;
	int mY;
	Texture* mTexture;
	Uint8 mAlpha = 255;
};

