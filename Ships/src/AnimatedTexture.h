#pragma once
#include "Animation.h"

class AnimatedTexture
{
public:
	void InitAnimTexture(int spriteWidth, int spriteHeight, int maxFrames, int frameRate);
	void ResetAnimationFrame();
	void SetSpriteXY(int x, int y);
	void OnAnimate();

	const SDL_Rect& GetSrcRect();
private:
	Animation mAnimation;
	int mSpriteWidth = 0;
	int mSpriteHeight = 0;
	
	int mSpriteX = 0;
	int mSpriteY = 0;
};

