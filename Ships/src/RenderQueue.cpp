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
		SDL_RenderCopy(sprite->GetTexture()->GetRenderer(), sprite->GetTexture()->GetSDLTexture(), &sprite->GetSrcRect(), &sprite->GetDstRect());
	}

	sprites.clear();
}

int RenderQueue::GetSpritesCount() const
{
	return sprites.size();
}

void RenderQueue::AddToRenderQueue(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder)
{
	std::shared_ptr<Sprite> ptr = std::make_shared<Sprite>(texture, srcRect, dstRect, renderOrder);
	sprites.push_back(ptr);
}