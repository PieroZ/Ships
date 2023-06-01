#pragma once

#include "Texture.h"

class Sprite
{
private:
	Texture* mTexture;
	SDL_Rect mSrcRect;
	SDL_Rect mDstRect;
	int mRenderOrder = 0;

public:
	Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder);
	~Sprite();
	Texture* GetTexture();
	SDL_Rect GetSrcRect() const;
	SDL_Rect GetDstRect() const;
	int GetRenderOrder() const;
};

