#include "Sprite.h"
#include "Log.h"


Sprite::Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder, bool drawSpriteRect, SDL_Color c, bool absolutePos) : mTexture(texture), mSrcRect(srcRect), mDstRect(dstRect), mRenderOrder(renderOrder), mDrawSpriteRect(drawSpriteRect), mRectColor(c), mAbsolutePos(absolutePos)
{
}

Sprite::Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, SDL_Point center, int renderOrder, bool drawSpriteRect, SDL_Color c, bool absolutePos) : mTexture(texture), mSrcRect(srcRect), mDstRect(dstRect), mRenderOrder(renderOrder), mAngle(angle), mCenter(center), mDrawSpriteRect(drawSpriteRect), mRectColor(c), mAbsolutePos(absolutePos)
{
}

Sprite::~Sprite()
{
}

Texture* Sprite::GetTexture()
{
    return mTexture;
}

SDL_Rect Sprite::GetSrcRect() const
{
    return mSrcRect;
}

SDL_Rect Sprite::GetDstRect() const
{
    return mDstRect;
}


double Sprite::GetAngle() const
{
    return mAngle;
}


SDL_Point Sprite::GetCenter() const
{
    return mCenter;
}

int Sprite::GetRenderOrder() const
{
    return mRenderOrder;
}

bool Sprite::GetDrawSpriteRectFlag() const
{
    return mDrawSpriteRect;
}

SDL_Color Sprite::GetDrawSpriteRectColor() const
{
    return mRectColor;
}

bool Sprite::IsAbsolutePos() const
{
    return mAbsolutePos;
}


