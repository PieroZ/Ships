#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

class Texture
{
private:
	std::string Filename;

	int mWidth = 0;
	int mHeight = 0;
	//int mRenderOrder = 0;
	//SDL_Rect mSrcRect;
	//SDL_Rect mDstRect;

	SDL_Renderer* mRenderer = NULL;
	SDL_Texture* mSDLTexture = NULL;

public:
	Texture();
	//Texture(SDL_Texture* SDLTexture);
	~Texture();

	int GetRenderOrder() const;
	SDL_Texture* GetSDLTexture();
	SDL_Renderer* GetRenderer();
	//SDL_Rect GetSrcRect() const;
	//SDL_Rect GetDstRect() const;

	void Cleanup();
	bool Load(SDL_Renderer* mRenderer, std::string Filename);
	bool LoadText(TTF_Font* font, const std::string& textureText, const SDL_Color& textColor);

	void Render(int X, int Y);

	void Render(int X, int Y, int mWidth, int mHeight);

	void Render(int X, int Y, int mWidth, int mHeight, int SX, int SY, int SWidth, int SHeight);

	void Render(int X, int Y, SDL_Color color);

	void RenderScaled(int x, int y);
	void RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight);
	void RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight);

	void AddToRenderQueue(int x, int y, int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int renderOrder);

	int GetWidth();
	int GetHeight();
};
