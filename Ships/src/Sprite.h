#pragma once

#include "Texture.h"

class Sprite
{
private:
	Texture* mTexture;
	SDL_Rect mSrcRect;
	SDL_Rect mDstRect;
	double mAngle = 0.0;
	SDL_Point mCenter = { 0, 0 };
	int mRenderOrder = 0;
	
	bool mDrawSpriteRect = false;
	SDL_Color mRectColor = { 0, 0, 0 };

	bool mAbsolutePos = false;

public:
	Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder, bool drawSpriteRect = false, SDL_Color c = { 0,0,0 }, bool absolutePos = false);
	Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, SDL_Point center, int renderOrder, bool drawSpriteRect = false, SDL_Color c = {0,0,0}, bool absolutePos = false);
	~Sprite();
	Texture* GetTexture();
	SDL_Rect GetSrcRect() const;
	SDL_Rect GetDstRect() const;
	double GetAngle() const;
	SDL_Point GetCenter() const;
	int GetRenderOrder() const;
	bool GetDrawSpriteRectFlag() const;
	SDL_Color GetDrawSpriteRectColor() const;
	bool IsAbsolutePos() const;
};

