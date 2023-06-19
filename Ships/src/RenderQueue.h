#pragma once
#include "Sprite.h"
#include <vector>
#include <memory>

class RenderQueue
{
private:
	std::vector<std::shared_ptr<Sprite>> sprites;

public:
	static RenderQueue& GetInstance();
public:
	RenderQueue(const RenderQueue&) = delete;
	void operator=(const RenderQueue&) = delete;

	void Render(SDL_Rect cameraRect);
	int GetSpritesCount() const;
	void AddToRenderQueue(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, int renderOrder, bool drawRectFlag = false, SDL_Color c = {0,0,0}, bool absolutePos = false);
	void AddToRenderQueue(Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect, double angle, const SDL_Point& center, int renderOrder, bool drawRectFlag = false, SDL_Color c = { 0,0,0 }, bool absolutePos = false);
private:
	RenderQueue();
};

