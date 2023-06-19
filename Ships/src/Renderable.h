#pragma once
#include "Texture.h"

class Renderable
{
public:
	Renderable();
	Renderable(int x, int y);
	virtual ~Renderable() = default;
	
	void SetTexture(Texture* texture);
	virtual void AddToRenderQueue(int renderOrder, bool drawRectFlag = false, SDL_Color c = { 0,0,0 });

protected:
	int mX;
	int mY;
	Texture* mTexture;
};

