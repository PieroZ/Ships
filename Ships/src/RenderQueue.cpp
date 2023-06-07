#include "RenderQueue.h"

#include <algorithm>

RenderQueue& RenderQueue::GetInstance()
{
	static RenderQueue instance;
	return instance;
}


RenderQueue::RenderQueue()
{
}

void RenderQueue::Render()
{
	// Sort the sprites based on the render order
	std::sort(sprites.begin(), sprites.end(), [](std::shared_ptr<Sprite> a, std::shared_ptr<Sprite> b)
		{
			return a->GetRenderOrder() < b->GetRenderOrder();
		});

	// Render the sprites in the sorted order
	for (const auto& sprite: sprites)
	{
		if (sprite->GetAngle() == 0.0)
		{
			SDL_RenderCopy(sprite->GetTexture()->GetRenderer(), sprite->GetTexture()->GetSDLTexture(), &sprite->GetSrcRect(), &sprite->GetDstRect());
		}
		else
		{
			SDL_RenderCopyEx(sprite->GetTexture()->GetRenderer(), sprite->GetTexture()->GetSDLTexture(), &sprite->GetSrcRect(), &sprite->GetDstRect(), sprite->GetAngle(), &sprite->GetCenter(), SDL_RendererFlip::SDL_FLIP_NONE);
		}

		if (sprite->GetDrawSpriteRectFlag())
		{
			SDL_RenderDrawRect(sprite->GetTexture()->GetRenderer(), &sprite->GetDstRect());
		}
	}

	sprites.clear();
}

int RenderQueue::GetSpritesCount() const
{
	return sprites.size();
}

void RenderQueue::AddToRenderQueue(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder, bool drawRectFlag/* = false*/)
{
	std::shared_ptr<Sprite> ptr = std::make_shared<Sprite>(texture, srcRect, dstRect, renderOrder, drawRectFlag);
	sprites.push_back(ptr);
}

void RenderQueue::AddToRenderQueue(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, const SDL_Point& center, int renderOrder, bool drawRectFlag /*= false*/)
{
	std::shared_ptr<Sprite> ptr = std::make_shared<Sprite>(texture, srcRect, dstRect, angle, center, renderOrder, drawRectFlag);
	sprites.push_back(ptr);
}