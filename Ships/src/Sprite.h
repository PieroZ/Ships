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
	Uint8 mAlpha;
	
	bool mDrawSpriteRect = false;

public:
	Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder, Uint8 alpha = 255, bool drawSpriteRect = false);
	Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, SDL_Point center, int renderOrder, Uint8 alpha = 255, bool drawSpriteRect = false);
	~Sprite();
	Texture* GetTexture();
	SDL_Rect GetSrcRect() const;
	SDL_Rect GetDstRect() const;
	double GetAngle() const;
	SDL_Point GetCenter() const;
	int GetRenderOrder() const;
	bool GetDrawSpriteRectFlag() const;
	Uint8 GetAlpha() const;
};

