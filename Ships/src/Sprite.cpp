#include "Sprite.h"
#include "Log.h"


Sprite::Sprite(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder) : mTexture(texture), mSrcRect(srcRect), mDstRect(dstRect), mRenderOrder(renderOrder)
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

int Sprite::GetRenderOrder() const
{
    return mRenderOrder;
}
