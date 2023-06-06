#include "Sprite.h"
#include "Log.h"


Sprite::Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder, Uint8 alpha, bool drawSpriteRect) : mTexture(texture), mSrcRect(srcRect), mDstRect(dstRect), mRenderOrder(renderOrder), mAlpha(alpha), mDrawSpriteRect(drawSpriteRect)
{
}

Sprite::Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, SDL_Point center, int renderOrder, Uint8 alpha, bool drawSpriteRect) : mTexture(texture), mSrcRect(srcRect), mDstRect(dstRect), mRenderOrder(renderOrder), mAngle(angle), mCenter(center), mAlpha(alpha), mDrawSpriteRect(drawSpriteRect)
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

Uint8 Sprite::GetAlpha() const
{
    return mAlpha;
}

