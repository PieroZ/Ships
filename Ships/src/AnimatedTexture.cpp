#include "AnimatedTexture.h"

void AnimatedTexture::InitAnimTexture(int spriteWidth, int spriteHeight, int maxFrames, int frameRate)
{
	mSpriteWidth = spriteWidth;
	mSpriteHeight = spriteHeight;
	mAnimation.SetMaxFrames(maxFrames);
	mAnimation.SetFrameRate(frameRate);
}

void AnimatedTexture::ResetAnimationFrame()
{
	mAnimation.SetCurrentFrame(0);
}

void AnimatedTexture::SetSpriteXY(int x, int y)
{
	mSpriteX = x * mSpriteWidth;
	mSpriteY = y * mSpriteHeight;
}

void AnimatedTexture::OnAnimate()
{
	mAnimation.OnAnimate();
}

const SDL_Rect& AnimatedTexture::GetSrcRect()
{
	return SDL_Rect{ mSpriteX + mAnimation.GetCurrentFrame() * mSpriteWidth, mSpriteY, mSpriteWidth, mSpriteHeight};
}
