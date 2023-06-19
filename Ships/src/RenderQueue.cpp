#include "RenderQueue.h"
#include "Colideable.h"
#include "Log.h"

#include <algorithm>

RenderQueue& RenderQueue::GetInstance()
{
	static RenderQueue instance;
	return instance;
}


RenderQueue::RenderQueue()
{
}

void RenderQueue::Render(SDL_Rect cameraRect)
{
	// Sort the sprites based on the render order
	std::sort(sprites.begin(), sprites.end(), [](std::shared_ptr<Sprite> a, std::shared_ptr<Sprite> b)
		{
			return a->GetRenderOrder() < b->GetRenderOrder();
		});

	// Render the sprites in the sorted order
	for (const auto& sprite: sprites)
	{
		if (!sprite->IsAbsolutePos() && !Colideable::CheckBoxCollision(sprite->GetDstRect(), cameraRect)) continue;

		//LOG_ERROR("O KURWA");
		SDL_Rect screenCoordinates;
		if (sprite->IsAbsolutePos())
		{
			screenCoordinates.x = sprite->GetDstRect().x;
			screenCoordinates.y = sprite->GetDstRect().y;
		}
		else
		{
			screenCoordinates.x = sprite->GetDstRect().x - cameraRect.x;
			screenCoordinates.y = sprite->GetDstRect().y - cameraRect.y;
		}
		screenCoordinates.w = sprite->GetDstRect().w;
		screenCoordinates.h = sprite->GetDstRect().h;

		if (sprite->GetAngle() == 0.0)
		{
			SDL_RenderCopy(sprite->GetTexture()->GetRenderer(), sprite->GetTexture()->GetSDLTexture(), &sprite->GetSrcRect(), &screenCoordinates);
		}
		else
		{
			SDL_RenderCopyEx(sprite->GetTexture()->GetRenderer(), sprite->GetTexture()->GetSDLTexture(), &sprite->GetSrcRect(), &screenCoordinates, sprite->GetAngle(), &sprite->GetCenter(), SDL_RendererFlip::SDL_FLIP_NONE);
		}

		if (sprite->GetDrawSpriteRectFlag())
		{
			SDL_Color c = sprite->GetDrawSpriteRectColor();
			SDL_SetRenderDrawColor(sprite->GetTexture()->GetRenderer(), c.r, c.g, c.b, 255);
			SDL_RenderDrawRect(sprite->GetTexture()->GetRenderer(), &sprite->GetDstRect());
			SDL_SetRenderDrawColor(sprite->GetTexture()->GetRenderer(), 0, 0, 0, 255);
		}
	}

	sprites.clear();
}

int RenderQueue::GetSpritesCount() const
{
	return sprites.size();
}

void RenderQueue::AddToRenderQueue(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder, bool drawRectFlag/* = false*/, SDL_Color c, bool absolutePos)
{
	std::shared_ptr<Sprite> ptr = std::make_shared<Sprite>(texture, srcRect, dstRect, renderOrder, drawRectFlag, c, absolutePos);
	sprites.push_back(ptr);
}

void RenderQueue::AddToRenderQueue(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, const SDL_Point& center, int renderOrder, bool drawRectFlag /*= false*/, SDL_Color c, bool absolutePos)
{
	std::shared_ptr<Sprite> ptr = std::make_shared<Sprite>(texture, srcRect, dstRect, angle, center, renderOrder, drawRectFlag, c, absolutePos);
	sprites.push_back(ptr);
}