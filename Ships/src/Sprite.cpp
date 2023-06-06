#include "Sprite.h"
#include "Log.h"


Sprite::Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder) : mTexture(texture), mSrcRect(srcRect), mDstRect(dstRect), mRenderOrder(renderOrder)
{
}

Sprite::Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, SDL_Point center, int renderOrder) : mTexture(texture), mSrcRect(srcRect), mDstRect(dstRect), mRenderOrder(renderOrder), mAngle(angle), mCenter(center)
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

