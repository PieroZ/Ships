#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>

class Texture
{
private:
	std::string Filename;

	int mWidth = 0;
	int mHeight = 0;

	SDL_Renderer* mRenderer = NULL;
	SDL_Texture* SDLTexture = NULL;

public:
	Texture();
	~Texture();

	bool Load(SDL_Renderer* mRenderer, std::string Filename);

	void Render(int X, int Y);

	void Render(int X, int Y, int mWidth, int mHeight);

	void Render(int X, int Y, int mWidth, int mHeight, int SX, int SY, int SWidth, int SHeight);

	void Render(int X, int Y, SDL_Color color);

	void RenderScaled(int x, int y);
	void RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight);
	void RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight);

	int GetWidth();
	int GetHeight();
};
