#include "Renderable.h"
#include "RenderQueue.h"
#include "Log.h"


Renderable::Renderable(int x, int y) : mX(x), mY(y)
{
    mTexture = nullptr;
}

void Renderable::SetTexture(Texture* texture)
{
    mTexture = texture;
}

void Renderable::AddToRenderQueue(int renderOrder)
{
    if (!mTexture)
    {
        LOG_ERROR("Trying to add nullptr to render queue!");
        return;
    }
    SDL_Rect dstRect = { mX, mX, mTexture->GetWidth(), mTexture->GetHeight() };

    SDL_Rect srcRect = mTexture->GetEntireTextureRect();
    RenderQueue::GetInstance().AddToRenderQueue(mTexture, srcRect, dstRect, renderOrder, mAlpha);
}
