#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>

class Texture
{
private:
	std::string Filename;

	int Width = 0;
	int Height = 0;

	SDL_Renderer* mRenderer = NULL;
	SDL_Texture* SDLTexture = NULL;

public:
	Texture();
	~Texture();

	bool Load(SDL_Renderer* mRenderer, std::string Filename);

	void Render(int X, int Y);

	void Render(int X, int Y, int Width, int Height);

	void Render(int X, int Y, int Width, int Height, int SX, int SY, int SWidth, int SHeight);

	void Render(int X, int Y, SDL_Color color);

	int GetWidth();
	int GetHeight();
};
