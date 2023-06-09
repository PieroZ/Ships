#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

class Texture
{
private:
	std::string Filename;

	// This value corresponds to the entire image width, meaning t hat if entire spritesheet is loaded into Texture that values will correspond to the spritesheet size rather than single sprite dimensions
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

	
	SDL_Texture* GetSDLTexture();
	SDL_Renderer* GetRenderer();
	//SDL_Rect GetSrcRect() const;
	//SDL_Rect GetDstRect() const;

	void SetAlpha(Uint8 alpha) const;

	void Cleanup();
	bool Load(SDL_Renderer* mRenderer, std::string Filename);
	bool LoadText(TTF_Font* font, const std::string& textureText, const SDL_Color& textColor);

	void Render(int mX, int mY);

	void Render(int mX, int mY, int mWidth, int mHeight);

	void Render(int mX, int mY, int mWidth, int mHeight, int SX, int SY, int SWidth, int SHeight);

	void Render(int mX, int mY, SDL_Color color);

	void RenderScaled(int x, int y);
	void RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight);
	void RenderScaled(int x, int y, int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight);

	void AddToRenderQueue(int x, int y, int normalResolutionWidth, int normalResolutionHeight, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int renderOrder, bool absolutePos = false);

	const SDL_Rect& GetEntireTextureRect() const;
	const SDL_Point& GetCenterPointOfTexture() const;
	int GetWidth();
	int GetHeight();
};
